#include <gtest/gtest.h>

#include <iostream>
#include <vector>

#include "../includes/Stack.h"
#include "../includes/Stack_impl.h"

TEST(StackTest, PushandPop) {
  Stack<uint32_t> s1;

  for (int i = 0; i <= 1e6; ++i) {
    s1.push(static_cast<uint32_t>(i));
    ASSERT_EQ(s1.top(), i);
  }

  for (int i = 1e6; i > 0; --i) {
    s1.pop();
    ASSERT_EQ(s1.top(), i - 1);
  }
}

TEST(StackTest, BPushandPop) {
  Stack<bool> s1;
  for(int i = 0; i < 1e6; ++i) {
    s1.push(true);
    ASSERT_EQ(s1.top(), true);
    s1.push(false);
    ASSERT_EQ(s1.top(), false);
    s1.push(true);
    ASSERT_EQ(s1.top(), true);
  }

  for(int i = 0; i < 1e6; ++i) {
    ASSERT_EQ(s1.top(), true);
    s1.pop();
    ASSERT_EQ(s1.top(), false);
    s1.pop();
    ASSERT_EQ(s1.top(), true);
    s1.pop();
  }
}

TEST(StackTest, Top) {
  Stack<uint32_t> s1;

  for (int i = 0; i < 1001; ++i) {
    s1.push(static_cast<uint32_t>(i * 2));
  }

  ASSERT_EQ(s1.top(), 2000);
}

TEST(StackTest, Size) {
  Stack<uint32_t> s2;

  for (int i = 0; i < 1e5; ++i) {
    s2.push(static_cast<uint32_t>(i * 2));
  }

  ASSERT_EQ(s2.size(), 1e5);
}

TEST(StackTest, Pop) {
  Stack<uint32_t> s3;

  for (uint32_t i = 0; i < 400; ++i) {
    s3.push(i);
  }

  for (uint32_t i = 0; i < 250; ++i) {
    s3.pop();
  }

  ASSERT_EQ(s3.size(), 150);
}

TEST(StackTest, IsEmpty) {
  Stack<uint32_t> s4;

  ASSERT_TRUE(s4.is_empty());

  s4.push(1);

  ASSERT_FALSE(s4.is_empty());
}

TEST(StackTest, Equality) {
  Stack<uint32_t> s1;
  Stack<uint32_t> s2;

  ASSERT_TRUE(s1 == s2);
}

TEST(StackTest, Swap) {
  Stack<uint32_t> s1;
  Stack<uint32_t> s11;
  Stack<uint32_t> s2;
  Stack<uint32_t> s21;

  for (uint32_t i = 0; i < 10; ++i) {
    s1.push(i);
  }
  s2.push(13);

  s11 = s1;
  s21 = s2;

  s1.swap(s2);

  ASSERT_TRUE(s1 == s21 && s2 == s11);
}

TEST(StackTest, Btop) {
  Stack<bool> s1;

  std::vector<bool> v1 = {true, false, true, true, true, false, false, false, true, false};

  for (bool item : v1) {
    s1.push(item);
  }

  ASSERT_EQ(s1.top(), false);

  v1.clear();
}

TEST(StackTest, Bsize) {
  Stack<bool> s1;

  for (int i = 0; i < 1e4; ++i) {
    bool elem = static_cast<bool>(i % 2);
    s1.push(elem);
  }

  ASSERT_EQ(s1.size(), 10000);
}

TEST(StackTest, BisEmpty) {
  Stack<bool> s1;

  ASSERT_TRUE(s1.is_empty());
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}