#ifndef d13166971d730f81fcf8b757f2ea239d1a0360d9f74e8f5afe60fba97105879c
#define d13166971d730f81fcf8b757f2ea239d1a0360d9f74e8f5afe60fba97105879c

#include "executor/Executor.h"

/**
 * @brief 指令类
 *
 */
class Command
{
public:
    virtual void command(position &pos) = 0;
    void move(int forward_or_backward, position &pos)
    {
        attribute _attr = pos.attr[pos.heading_code];
        pos.position_x += (_attr.XorY ^ Y) * _attr.op * forward_or_backward;
        pos.position_y += (_attr.XorY ^ X) * _attr.op * forward_or_backward;
    }
};

class TurnLeft : public Command
{
public:
    void command(position &pos)
    {
        pos.heading_code = ((pos.heading_code << 1) & 0b1111) | (pos.heading_code >> 3);
    }
};

class TurnRight : public Command
{
public:
    void command(position &pos)
    {
        pos.heading_code = (pos.heading_code >> 1) | ((pos.heading_code << 3) & 0b1111);
    }
};

class TurnRound : public Command
{
public:
    void command(position &pos)
    {
        pos.heading_code = ((pos.heading_code << 2) & 0b1111) | (pos.heading_code >> 2);
    }
};

class Forward : public Command
{
public:
    void command(position &pos)
    {
        move(1, pos);
    }
};

class Backward : public Command
{
public:
    void command(position &pos)
    {
        move(-1, pos);
    }
};

#endif // d13166971d730f81fcf8b757f2ea239d1a0360d9f74e8f5afe60fba97105879c
