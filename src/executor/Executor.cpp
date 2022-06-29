#include "executor/Executor.h"

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
        pos.heading_code = ((pos.heading_code << 1) & 0b1111) | (pos.heading_code >> 3);
    }
    else if (action == TURN_RIGHT) {
        pos.heading_code = (pos.heading_code >> 1) | ((pos.heading_code << 3) & 0b1111);
    }
    else if (action == FORWARD) {
        move(1);
    }
    else if (action == BACKWARD) {
        move(-1);
    }
    else if (action == TURN_ROUND) {
        pos.heading_code = ((pos.heading_code << 2) & 0b1111) | (pos.heading_code >> 2);
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

void Executor::move(int forward_or_backward) {
    attr a = pos.heading_attribute[pos.heading_code];
    pos.position_x += (a.XorY ^ Y) * a.op * forward_or_backward;
    pos.position_y += (a.XorY ^ X) * a.op * forward_or_backward;
}