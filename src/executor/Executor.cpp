#include "executor/Executor.h"
#include "Command/Command.h"
#include "alert/alert.h"
#include "clean/clean.h"

/**
 * @brief 根据init_pk初始化位置信息
 *
 * @param init_pk 初始化协议包
 * @return true 初始化成功
 * @return false 初始化失败
 */
bool Executor::init(init_pack init_pk)
{
    // 判断init_pk.heading是否合法
    std::string h = init_pk.heading;
    if (h != NORTH && h != EAST && h != SOUTH && h != WEST)
        return false;

    pos.position_x = init_pk.x;
    pos.position_y = init_pk.y;
    pos.attr = {
        {0b1000, {NORTH, Y, 1}},
        {0b0100, {EAST, X, 1}},
        {0b0010, {SOUTH, Y, -1}},
        {0b0001, {WEST, X, -1}}
    };
    pos.heading_to_code = {
        {NORTH, 0b1000},
        {EAST, 0b0100},
        {SOUTH, 0b0010},
        {WEST, 0b0001}
    };
    pos.heading_code = pos.heading_to_code[h];
    return true;
}

/**
 * @brief 采取行动
 * 可执行宏定义的所有行动
 * @param action 行动指令
 * @return true 执行行动指令成功
 * @return false 执行行动指令失败
 */
bool Executor::take_action(std::string action)
{
    Command *cmd = NULL;
    if (action == TURN_LEFT)
    {
        cmd = new TurnLeft;
    }
    else if (action == TURN_RIGHT)
    {
        cmd = new TurnRight;
    }
    else if (action == FORWARD)
    {
        cmd = new Forward;
    }
    else if (action == BACKWARD)
    {
        cmd = new Backward;
    }
    else if (action == TURN_ROUND)
    {
        cmd = new TurnRound;
    }
    else
    {
        return false;
    }
    cmd->command(pos);
    delete cmd;

    // 获取当前位置需要执行的操作并调用相应的接口
    operate_position c = {
        pos.position_x, pos.position_y, -1
    };
    c.operation = is_operate_position(std::make_pair(c.x, c.y));
    call_api(c);
    return true;
}

/**
 * @brief 获取位置信息
 *
 * @return position_readable 人类可读的位置信息
 */
position_readable Executor::get_position()
{
    position_readable return_pos;
    return_pos.x = pos.position_x;
    return_pos.y = pos.position_y;
    return_pos.heading = pos.attr[pos.heading_code].heading;
    return return_pos;
}

/**
 * @brief 设置有操作的坐标点
 *
 * @param p 有操作的坐标点
 * @param operate_type 操作类型
 * @return int -1表示已经满了，0表示插入成功，其他表示这个点已经具有操作类型，返回操作类型数字
 */
int Executor::set_operate_position(operate_position &c)
{
    if (operate_pos.size() >= MAX_OPERATION)
        return -1;

    for (int i = OPERATION_BEGIN; i < OPERATION_END; i++)
    {
        operate_position tmp = {
            c.x, c.y, i
        };
        std::set<operate_position>::iterator it = operate_pos.find(tmp);
        if (it != operate_pos.end())
            return it->operation;
    }

    operate_pos.insert(c);
    return 0;
}

/**
 * @brief 删除有操作的坐标点
 *
 * @param p 需要删除的坐标点
 * @param operate_type 该坐标点的操作类型
 * @return true 删除成功
 * @return false 删除失败
 */
bool Executor::cancel_operate_position(operate_position &c)
{
    return operate_pos.erase(c);
}

/**
 * @brief 检查当前坐标点是否需要操作
 *
 * @param p 需要检查的坐标点
 * @return NO_OPERATION 无操作
 * @return DANGEROUS 告警操作
 * @return CLEAN 清扫操作
 */
int Executor::is_operate_position(std::pair<int, int> p)
{
    for (int i = OPERATION_BEGIN; i < OPERATION_END; i++)
    {
        operate_position tmp = {
            p.first, p.second, i
        };
        std::set<operate_position>::iterator it = operate_pos.find(tmp);
        if (it != operate_pos.end())
            return it->operation;
    }
    return NO_OPERATION;
}

/**
 * @brief 对给定位置调用需要调用的接口
 *
 * @param c 可能存在操作的位置
 */
void Executor::call_api(operate_position &c)
{
    /**
     * c.operation
     * DANGEROUS 调用alert接口
     * CLEAN 调用clean接口并删除当前位置的clean操作
     * NO_OPERATION 不执行任何操作
     */
    switch (c.operation)
    {
    case DANGEROUS:
        alert(IN_DANGEROUS, c.x, c.y);
        break;
    case CLEAN:
    {
        clean(c.x, c.y);
        operate_position tmp = {
            c.x, c.y, CLEAN
        };
        operate_pos.erase(tmp);
        break;
    }
    default:
        break;
    }
}
