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

TEST_F(ExecutorTest, init_exectuor_north) {
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

TEST_F(ExecutorTest, init_exectuor_east) {
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

TEST_F(ExecutorTest, init_exectuor_south) {
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

TEST_F(ExecutorTest, init_exectuor_west) {
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

TEST_F(ExecutorTest, init_executor_false) {
    Executor executor;
    init_pack pk = {
        5, 10, "中"
    };

    ASSERT_EQ(executor.init(pk), false);
}

TEST_F(ExecutorTest, no_init_executor_get_pos) {
    Executor executor;

    position_readable p = executor.get_position();
    position_readable q = {
        0, 0, NORTH
    };

    ASSERT_EQ(p.heading, q.heading);
}

TEST_F(ExecutorTest, executor_turn_left1) {
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

TEST_F(ExecutorTest, executor_turn_left2) {
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

TEST_F(ExecutorTest, executor_turn_right1) {
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

TEST_F(ExecutorTest, executor_turn_right2) {
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

TEST_F(ExecutorTest, executor_forward_north) {
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

TEST_F(ExecutorTest, executor_forward_east) {
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

TEST_F(ExecutorTest, executor_forward_south) {
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

TEST_F(ExecutorTest, executor_forward_west) {
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

TEST_F(ExecutorTest, executor_backward_north) {
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

TEST_F(ExecutorTest, executor_backward_east) {
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

TEST_F(ExecutorTest, executor_backward_south) {
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

TEST_F(ExecutorTest, executor_backward_west) {
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

TEST_F(ExecutorTest, executor_turn_round_from_north) {
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

TEST_F(ExecutorTest, executor_turn_round_from_east) {
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

TEST_F(ExecutorTest, executor_turn_round_from_south) {
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

TEST_F(ExecutorTest, executor_turn_round_from_west) {
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

