#ifndef FE0C20F3603C4B6B9DBF2214C001D90A
#define FE0C20F3603C4B6B9DBF2214C001D90A

// 动作宏
#define TURN_LEFT "turn left"
#define TURN_RIGHT "turn right"
#define FORWARD "forward"
#define BACKWARD "backward"
#define TURN_ROUND "turn round"

// 方向宏
#define NORTH "北"
#define EAST "东"
#define WEST "西"
#define SOUTH "南"

// 控制最大数量的宏
#define MAX_OPERATION 16
#define MAX_ACTION 5

// 代表沿X轴还是Y轴的宏
#define X 0
#define Y 1

#include <string>
#include <map>
#include <set>

// 操作类型枚举变量
enum
{
    NO_OPERATION,
    DANGEROUS,
    OPERATION_BEGIN = 1,
    CLEAN,
    OPERATION_END
};

/**
 * @brief 初始化协议包
 *
 */
typedef struct _init_pack
{
    int x;               // 初始坐标x
    int y;               // 初始坐标y
    std::string heading; // 初始朝向
} init_pack;

/**
 * @brief 具有操作的点位置
 *
 */
typedef struct _operate_position
{
    int x;         // 坐标x
    int y;         // 坐标y
    int operation; // 0表示不是操作点，1表示是危险坐标点，2表示是需要清扫的点
    /**
     * @brief 重载比较运算符
     * 按照关键字顺序比较
     * @param a 具有操作的点a
     * @param b 具有操作的点b
     * @return true a < b
     * @return false a > b
     */
    friend bool operator<(_operate_position a, _operate_position b)
    {
        if (a.x < b.x)
            return true;
        else if (a.x == b.x)
        {
            if (a.y < b.y)
                return true;
            else if (a.y == b.y)
            {
                return a.operation < b.operation;
            }
        }
        return false;
    }
} operate_position;

/**
 * @brief 当前位置具有的属性
 *
 */
typedef struct _attribute
{
    std::string heading; // 朝向
    bool XorY;           // 当前朝向是沿着x还是沿着y，false---X, true---Y
    int op;              // 操作符，1为正，-1为负，直接*op即可
} attribute;

/**
 * @brief Executor内部的position实现
 *
 */
typedef struct _position
{
    int position_x;                             // 坐标x
    int position_y;                             // 坐标y
    int heading_code;                           // 北1000 东0100 南0010 西0001
    std::map<int, attribute> attr;              // 当前坐标具有的属性
    std::map<std::string, int> heading_to_code; // 朝向和heading_code的映射表
} position;

/**
 * @brief 人类可理解的位置信息
 *
 */
typedef struct _position_readable
{
    int x;               // 坐标x
    int y;               // 坐标y
    std::string heading; // 朝向
    /**
     * @brief 重载比较运算符
     * 两个position_readable相等时返回true
     * @param p position_readable 1
     * @param q position_readable 2
     * @return true 两个position_readable相等
     * @return false 两个position_readable不相等
     */
    friend bool operator==(_position_readable p, _position_readable q)
    {
        if (p.x == q.x && p.y == q.y && p.heading == q.heading)
            return true;
        else
            return false;
    }
} position_readable;

/**
 * @brief Executor类
 *
 */
class Executor
{
public:
    /**
     * @brief Construct a new Executor object
     *
     * @param name 初始化名
     */
    explicit Executor(std::string name) : name(std::move(name))
    {
        init();
    }

    /**
     * @brief Construct a new Executor object
     * 无名初始化
     */
    explicit Executor()
    {
        name = "Default name";
        init();
    }

    /**
     * @brief Get the name object
     *
     * @return const std::string& 返回Exeutor名
     */
    const std::string &get_name() const
    {
        return name;
    }

    bool init(init_pack init_pk = {0, 0, NORTH});
    bool take_action(std::string action);
    position_readable get_position();
    int set_operate_position(operate_position &c);
    bool cancel_operate_position(operate_position &c);
    int is_operate_position(std::pair<int, int> p);
    void call_api(operate_position &c);

private:
    std::string name;                       // 名字
    position pos;                           // 位置
    std::set<operate_position> operate_pos; // 有操作的位置
};

#endif // FE0C20F3603C4B6B9DBF2214C001D90A
