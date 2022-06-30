#include <gtest/gtest.h>
#include "executor/Executor.h"

struct ExecutorTest : testing::Test
{
protected:
	void SetUp() override
    {
	}

	void TearDown() override
    {
	}
};

TEST_F(ExecutorTest, should_get_executor_name)
{
    Executor executor("demo");

    ASSERT_EQ(executor.get_name(), "demo");
}

TEST_F(ExecutorTest, init_exectuor_north)
{
    Executor executor;
    init_pack pk = {
        5, 10, NORTH
    };
    executor.init(pk);

    position_readable p = executor.get_position();
    position_readable q = {
        5, 10, NORTH
    };

    ASSERT_EQ(p, q);
}

TEST_F(ExecutorTest, init_exectuor_east)
{
    Executor executor;
    init_pack pk = {
        5, 10, EAST
    };
    executor.init(pk);

    position_readable p = executor.get_position();
    position_readable q = {
        5, 10, EAST
    };

    ASSERT_EQ(p, q);
}

TEST_F(ExecutorTest, init_exectuor_south)
{
    Executor executor;
    init_pack pk = {
        5, 10, SOUTH
    };
    executor.init(pk);

    position_readable p = executor.get_position();
    position_readable q = {
        5, 10, SOUTH
    };

    ASSERT_EQ(p, q);
}

TEST_F(ExecutorTest, init_exectuor_west)
{
    Executor executor;
    init_pack pk = {
        5, 10, WEST
    };
    executor.init(pk);

    position_readable p = executor.get_position();
    position_readable q = {
        5, 10, WEST
    };

    ASSERT_EQ(p, q);
}

TEST_F(ExecutorTest, init_executor_false)
{
    Executor executor;
    init_pack pk = {
        5, 10, "中"
    };

    ASSERT_EQ(executor.init(pk), false);
}

TEST_F(ExecutorTest, no_init_executor_get_pos)
{
    Executor executor;

    position_readable p = executor.get_position();
    position_readable q = {
        0, 0, NORTH
    };

    ASSERT_EQ(p.heading, q.heading);
}

TEST_F(ExecutorTest, executor_turn_left1)
{
    Executor executor;
    init_pack pk = {
        5, 10, WEST
    };
    executor.init(pk);

    executor.take_action(TURN_LEFT);
    position_readable p = executor.get_position();
    position_readable q = {
        5, 10, SOUTH
    };

    ASSERT_EQ(p, q);
}

TEST_F(ExecutorTest, executor_turn_left2)
{
    Executor executor;
    init_pack pk = {
        5, 10, NORTH
    };
    executor.init(pk);

    executor.take_action(TURN_LEFT);
    position_readable p = executor.get_position();
    position_readable q = {
        5, 10, WEST
    };

    ASSERT_EQ(p, q);
}

TEST_F(ExecutorTest, executor_turn_right1)
{
    Executor executor;
    init_pack pk = {
        5, 10, WEST
    };
    executor.init(pk);

    executor.take_action(TURN_RIGHT);
    position_readable p = executor.get_position();
    position_readable q = {
        5, 10, NORTH
    };

    ASSERT_EQ(p, q);
}

TEST_F(ExecutorTest, executor_turn_right2)
{
    Executor executor;
    init_pack pk = {
        5, 10, NORTH
    };
    executor.init(pk);

    executor.take_action(TURN_RIGHT);
    position_readable p = executor.get_position();
    position_readable q = {
        5, 10, EAST
    };

    ASSERT_EQ(p, q);
}

TEST_F(ExecutorTest, executor_forward_north)
{
    Executor executor;
    init_pack pk = {
        5, 10, NORTH
    };
    executor.init(pk);

    position_readable p = executor.get_position();
    p.y++;
    executor.take_action(FORWARD);
    position_readable q = executor.get_position();

    ASSERT_EQ(p, q);
}

TEST_F(ExecutorTest, executor_forward_east)
{
    Executor executor;
    init_pack pk = {
        5, 10, EAST
    };
    executor.init(pk);

    position_readable p = executor.get_position();
    p.x++;
    executor.take_action(FORWARD);
    position_readable q = executor.get_position();

    ASSERT_EQ(p, q);
}

TEST_F(ExecutorTest, executor_forward_south)
{
    Executor executor;
    init_pack pk = {
        5, 10, SOUTH
    };
    executor.init(pk);

    position_readable p = executor.get_position();
    p.y--;
    executor.take_action(FORWARD);
    position_readable q = executor.get_position();

    ASSERT_EQ(p, q);
}

TEST_F(ExecutorTest, executor_forward_west)
{
    Executor executor;
    init_pack pk = {
        5, 10, WEST
    };
    executor.init(pk);

    position_readable p = executor.get_position();
    p.x--;
    executor.take_action(FORWARD);
    position_readable q = executor.get_position();

    ASSERT_EQ(p, q);
}

TEST_F(ExecutorTest, executor_backward_north)
{
    Executor executor;
    init_pack pk = {
        5, 10, NORTH
    };
    executor.init(pk);

    position_readable p = executor.get_position();
    p.y--;
    executor.take_action(BACKWARD);
    position_readable q = executor.get_position();

    ASSERT_EQ(p, q);
}

TEST_F(ExecutorTest, executor_backward_east)
{
    Executor executor;
    init_pack pk = {
        5, 10, EAST
    };
    executor.init(pk);

    position_readable p = executor.get_position();
    p.x--;
    executor.take_action(BACKWARD);
    position_readable q = executor.get_position();

    ASSERT_EQ(p, q);
}

TEST_F(ExecutorTest, executor_backward_south)
{
    Executor executor;
    init_pack pk = {
        5, 10, SOUTH
    };
    executor.init(pk);

    position_readable p = executor.get_position();
    p.y++;
    executor.take_action(BACKWARD);
    position_readable q = executor.get_position();

    ASSERT_EQ(p, q);
}

TEST_F(ExecutorTest, executor_backward_west)
{
    Executor executor;
    init_pack pk = {
        5, 10, WEST
    };
    executor.init(pk);

    position_readable p = executor.get_position();
    p.x++;
    executor.take_action(BACKWARD);
    position_readable q = executor.get_position();

    ASSERT_EQ(p, q);
}

TEST_F(ExecutorTest, executor_turn_round_from_north)
{
    Executor executor;
    init_pack pk = {
        5, 10, NORTH
    };
    executor.init(pk);

    position_readable p = executor.get_position();
    p.heading = SOUTH;

    executor.take_action(TURN_ROUND);
    position_readable q = executor.get_position();

    ASSERT_EQ(p, q);
}

TEST_F(ExecutorTest, executor_turn_round_from_east)
{
    Executor executor;
    init_pack pk = {
        5, 10, EAST
    };
    executor.init(pk);

    position_readable p = executor.get_position();
    p.heading = WEST;

    executor.take_action(TURN_ROUND);
    position_readable q = executor.get_position();

    ASSERT_EQ(p, q);
}

TEST_F(ExecutorTest, executor_turn_round_from_south)
{
    Executor executor;
    init_pack pk = {
        5, 10, SOUTH
    };
    executor.init(pk);

    position_readable p = executor.get_position();
    p.heading = NORTH;

    executor.take_action(TURN_ROUND);
    position_readable q = executor.get_position();

    ASSERT_EQ(p, q);
}

TEST_F(ExecutorTest, executor_turn_round_from_west)
{
    Executor executor;
    init_pack pk = {
        5, 10, WEST
    };
    executor.init(pk);

    position_readable p = executor.get_position();
    p.heading = EAST;

    executor.take_action(TURN_ROUND);
    position_readable q = executor.get_position();

    ASSERT_EQ(p, q);
}

TEST_F(ExecutorTest, executor_set_dangerous_position)
{
    Executor executor;
    init_pack pk = {
        5, 10, WEST
    };
    executor.init(pk);

    operate_position c = {
        6, 11, DANGEROUS
    };
    
    ASSERT_EQ(executor.set_operate_position(c), 0);
}

TEST_F(ExecutorTest, executor_move_to_dangerous_position)
{
    Executor executor;
    init_pack pk = {
        5, 10, WEST
    };
    executor.init(pk);

    operate_position c = {
        6, 11, DANGEROUS
    };
    executor.set_operate_position(c);
    executor.take_action(BACKWARD);
    executor.take_action(TURN_RIGHT);
    executor.take_action(FORWARD);
    executor.take_action(TURN_ROUND);

    ASSERT_EQ(true, true);
}

TEST_F(ExecutorTest, executor_set_clean_position)
{
    Executor executor;
    init_pack pk = {
        5, 10, WEST
    };
    executor.init(pk);

    operate_position c = {
        6, 11, CLEAN
    };

    ASSERT_EQ(executor.set_operate_position(c), 0);
}

TEST_F(ExecutorTest, executor_move_to_clean_position)
{
    Executor executor;
    init_pack pk = {
        5, 10, WEST
    };
    executor.init(pk);

    operate_position c = {
        6, 11, CLEAN
    };
    executor.set_operate_position(c);
    executor.take_action(BACKWARD);
    executor.take_action(TURN_RIGHT);
    executor.take_action(FORWARD);
    executor.take_action(TURN_ROUND);

    ASSERT_EQ(true, true);
}

TEST_F(ExecutorTest, executor_repeatitively_set_dangerous_position)
{
    Executor executor;
    init_pack pk = {
        5, 10, WEST
    };
    executor.init(pk);

    operate_position c = {
        6, 11, DANGEROUS
    };
    executor.set_operate_position(c);

    ASSERT_EQ(executor.set_operate_position(c), DANGEROUS);
}

TEST_F(ExecutorTest, executor_repeatitively_set_clean_position)
{
    Executor executor;
    init_pack pk = {
        5, 10, WEST
    };
    executor.init(pk);

    operate_position c = {
        6, 11, CLEAN
    };
    executor.set_operate_position(c);

    ASSERT_EQ(executor.set_operate_position(c), CLEAN);
}

TEST_F(ExecutorTest, executor_set_multiple_operations_position)
{
    Executor executor;
    init_pack pk = {
        5, 10, WEST
    };
    executor.init(pk);

    int oper_type = CLEAN;
    operate_position c = {
        6, 11, CLEAN
    };
    executor.set_operate_position(c);
    c.operation = DANGEROUS;

    ASSERT_EQ(executor.set_operate_position(c), oper_type);
}

TEST_F(ExecutorTest, executor_set_max_operation_positions)
{
    Executor executor;
    init_pack pk = {
        5, 10, WEST
    };
    executor.init(pk);

    // 设置MAN_OPERATION个position
    for (int i = 0; i < MAX_OPERATION; i++) {
        operate_position c = {
            i, i, CLEAN
        };
        executor.set_operate_position(c);
    }

    operate_position c = {
        100, 100, CLEAN
    };
    ASSERT_EQ(executor.set_operate_position(c), -1);
}

TEST_F(ExecutorTest, executor_cancel_operate_position_success)
{
    Executor executor;
    init_pack pk = {
        5, 10, WEST
    };
    executor.init(pk);

    operate_position c = {
        6, 11, CLEAN
    };
    executor.set_operate_position(c);

    ASSERT_EQ(executor.cancel_operate_position(c), true);
}

TEST_F(ExecutorTest, executor_cancel_operate_position_fail_by_cancel_no_operation_position)
{
    Executor executor;
    init_pack pk = {
        5, 10, WEST
    };
    executor.init(pk);

    operate_position c = {
        6, 11, CLEAN
    };

    ASSERT_EQ(executor.cancel_operate_position(c), false);
}

TEST_F(ExecutorTest, executor_cancel_operate_position_fail_by_cancel_wrong_operation_position)
{
    Executor executor;
    init_pack pk = {
        5, 10, WEST
    };
    executor.init(pk);

    operate_position c = {
        6, 11, CLEAN
    };
    executor.set_operate_position(c);
    c.operation = DANGEROUS;

    ASSERT_EQ(executor.cancel_operate_position(c), false);
}

TEST_F(ExecutorTest, executor_is_clean_position)
{
    Executor executor;
    init_pack pk = {
        5, 10, WEST
    };
    executor.init(pk);

    operate_position c = {
        6, 11, CLEAN
    };
    executor.set_operate_position(c);

    ASSERT_EQ(executor.is_operate_position(std::make_pair(c.x, c.y)), CLEAN);
}

TEST_F(ExecutorTest, executor_is_dangerous_position)
{
    Executor executor;
    init_pack pk = {
        5, 10, WEST
    };
    executor.init(pk);

    operate_position c = {
        6, 11, DANGEROUS
    };
    executor.set_operate_position(c);

    ASSERT_EQ(executor.is_operate_position(std::make_pair(c.x, c.y)), DANGEROUS);
}

TEST_F(ExecutorTest, executor_not_operation_position)
{
    Executor executor;
    init_pack pk = {
        5, 10, WEST
    };
    executor.init(pk);

    operate_position c = {
        6, 11, DANGEROUS
    };
    executor.set_operate_position(c);
    c.x = c.y = 15;
    c.operation = CLEAN;
    executor.set_operate_position(c);

    ASSERT_EQ(executor.is_operate_position(std::make_pair(c.x, c.y + 1)), NO_OPERATION);
}
