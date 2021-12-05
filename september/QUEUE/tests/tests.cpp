#include <gtest/gtest.h>

#include "../Queue/includes/circular_queue_impl.hpp"
#include "../Queue/includes/stack_queue_impl.hpp"


#ifdef CIRCULAR_IMPL
using circular_queue::Queue;
#endif

#ifdef STACK_IMPL
using stack_queue::Queue;
#endif

static const int kNumTests = 1e6;

TEST(Queue, IsEmpty) {
  Queue<int> q1;
  EXPECT_TRUE(q1.is_empty());

  q1.push(0);
  EXPECT_FALSE(q1.is_empty());
}

TEST(Queue, Size) {
  Queue<int> q1;
  EXPECT_EQ(q1.size(), 0);

  for (int i = 1; i < kNumTests; ++i) {
    q1.push(i);
    EXPECT_EQ(q1.size(), i);
  }
}

TEST(Queue, PushAndRear) {
  Queue<int> q1;

  for (int i = 0; i < kNumTests; ++i) {
    q1.push(i);
    EXPECT_EQ(q1.rear(), i);
  }
}

TEST(Queue, PopAndFront) {
  Queue<int> q1;

  for (int i = 0; i < kNumTests; ++i) {
    q1.push(i);
  }

  for (int i = 0; i < kNumTests; ++i) {
    EXPECT_EQ(q1.front(), i);
    q1.pop();
  }
}

TEST(Queue, CopyConstruct) {
  Queue<int> q1;

  for (int i = 0; i < kNumTests; ++i) {
    q1.push(i);
  }

  Queue<int> q2(q1);
  for (int i = 0; i < kNumTests; ++i) {
    EXPECT_EQ(q2.front(), i);
    q2.pop();
  }
}

TEST(Queue, MoveConstruct) {
  Queue<int> q1;
  for (int i = 0; i < kNumTests; ++i) {
    q1.push(i);
    ASSERT_EQ(q1.rear(), i);
  }
  Queue<int> q2(std::move(q1));
  for (int i = 0; i < kNumTests; ++i) {
    ASSERT_EQ(q2.front(), i);
    q2.pop();
  }
}

TEST(Queue, EqOperator) {
  Queue<int> q1;

  for (int i = 0; i < kNumTests; ++i) {
    q1.push(i);
  }

  Queue<int> q2 = q1;
  for (int i = 0; i < kNumTests; ++i) {
    EXPECT_EQ(q2.front(), i);
    q2.pop();
  }
}

TEST(BoolQueue, IsEmpty) {
  Queue<bool> q1;
  EXPECT_TRUE(q1.is_empty());

  q1.push(true);
  EXPECT_FALSE(q1.is_empty());
}

TEST(BoolQueue, Size) {
  Queue<bool> q1;
  EXPECT_EQ(q1.size(), 0);

  for (int i = 1; i < kNumTests; ++i) {
    q1.push(true);
    EXPECT_EQ(q1.size(), i);
  }
}

TEST(BoolQueue, PushAndRear) {
  Queue<bool> q1;

  for (int i = 0; i < kNumTests; ++i) {
    q1.push(true);
    EXPECT_EQ(q1.rear(), true);
    q1.push(false);
    EXPECT_EQ(q1.rear(), false);
    q1.push(true);
    EXPECT_EQ(q1.rear(), true);
  }
}

TEST(BoolQueue, PopAndFront) {
  Queue<bool> q1;

  for (int i = 0; i < kNumTests; ++i) {
    q1.push(true);
    q1.push(false);
    q1.push(true);
  }

  for (int i = 0; i < kNumTests; ++i) {
    EXPECT_EQ(q1.front(), true);
    q1.pop();
    EXPECT_EQ(q1.front(), false);
    q1.pop();
    EXPECT_EQ(q1.front(), true);
    q1.pop();
  }
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}