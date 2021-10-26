#include <iostream>
#include <gtest/gtest.h>
#include <vector>

#include "includes/Stack.h"
#include "includes/Stack_impl.h"

TEST(Top) {
    Stack<uint32_t> s1;

    for(int i = 0; i < 1001; ++i) {
        s1.push(i * 2);
    }

    ASSERT_EQ(s1.top(), 2000);
}

TEST(Size) {
    Stack<uint32_t> s2;

    for(int i = 0; i < 1e5; ++i) {
        s2.push(i * 2);
    }

    ASSERT_EQ(s2.size(), 1e5);
}

TEST (Pop) {
    Stack<uint32_t> s3;

    for(uint32_t i = 0; i < 400; ++i) {
        s3.push(i);
    }

    for (uint32_t i = 0; i < 250; ++i) {
        s3.pop();
    }

    ASSERT_EQ(s3.size(), 150);
}

TEST (IsEmpty) {
    Stack<uint32_t> s4;

    ASSER_TRUE(s4.is_empty());

    s4.push(1);

    ASSER_FALSE(s4.is_empty());
}

TEST(Equality) {
    Stack<uint32_t> s1;
    Stack<uint32_t> s2;

    ASSER_TRUE(s1 == s2);
}

TEST (Swap) {
    Stack<uint32_t> s1, s11, s2, s21;

    for(uint32_t i = 0; i < 10; ++i) {
        s1.push(i);
    }
    s2.push(13);

    s11 = s1;
    s21 = s2;

    s1.swap(s2);

    ASSER_TRUE(s1 == s21 && s2 == s11);
}

TEST(Btop) {
    Stack<bool> s1;

    std::vector<bool> v1 = {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1};

    for(bool item: v1){
        s1.push(item);
    }

    ASSERT_EQ(s1.top(), 0);
}

TEST (Bsize) {
    Stack<bool> s1;

    for (int i = 0; i < 1e4; ++i) {
        s1.push(i % 2);
    }

    ASSERT_EQ(s1.size(), 10000)
}

TEST (BisEmpty) {
    Stack<bool> s1;

    ASSER_TRUE(s1.is_empty());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}