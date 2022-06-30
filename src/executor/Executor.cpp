#include "executor/Executor.h"
#include "Command/Command.h"
#include "../deps/alert/alert.h"

bool Executor::init(init_pack init_pk) {
    // 判断init_pk.heading是否合法
    std::string h = init_pk.heading;
    if (h != NORTH && h != EAST && h != SOUTH && h != WEST) return false;

    pos.position_x = init_pk.x;
    pos.position_y = init_pk.y;
    pos.heading_attribute = {
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

bool Executor::take_action(std::string action) {
    if (action == TURN_LEFT) {
        Turnleft c;
        c.command(pos);
    }
    else if (action == TURN_RIGHT) {
        Turnright c;
        c.command(pos);
    }
    else if (action == FORWARD) {
        Forward c;
        c.command(pos);
    }
    else if (action == BACKWARD) {
        Backward c;
        c.command(pos);
    }
    else if (action == TURN_ROUND) {
        Turnround c;
        c.command(pos);
    }

    if (dangerous_position.find(std::make_pair(pos.position_x, pos.position_y)) != dangerous_position.end()) {
        alert(IN_DANGEROUS, pos.position_x, pos.position_y);
    }
    return true;
}

position_readable Executor::get_position() {
    position_readable return_pos;
    return_pos.x = pos.position_x;
    return_pos.y = pos.position_y;
    return_pos.heading = pos.heading_attribute[pos.heading_code].heading;
    return return_pos;
}

void Executor::set_dangerous_position(std::pair<int, int> p) {
    dangerous_position.insert(p);
}