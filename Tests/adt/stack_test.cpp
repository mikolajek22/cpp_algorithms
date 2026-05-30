#include <gtest/gtest.h>
#include <adt/stack.h>

#define RANDOM_NUMBER   4854

TEST (StackTest, Push)
{
    const uint8_t stackSize = 10;
    Stack<int, stackSize> s;

    int val1 = RANDOM_NUMBER;
    StackStatus status;

    for (uint8_t i = 0; i < stackSize; i++)
    {
        status = s.push(val1 + i);
        EXPECT_EQ(status, STACK_OK);
    }
    status = s.push(67);
    EXPECT_EQ(status, STACK_FULL);
}

TEST (StackTest, Pop)
{
    const uint8_t stackSize = 10;
    Stack<int, stackSize> s;

    int val1 = RANDOM_NUMBER;
    int val2 = 0;
    StackStatus status;

    for (uint8_t i = 0; i < stackSize; i++)
    {
        s.push(val1 + i);
    }
    
    for (uint8_t i = 0; i < stackSize; i++)
    {
        status = s.pop(val2);
        EXPECT_EQ(status, STACK_OK);
        EXPECT_EQ(val1 + stackSize -1 - i, val2);
    }
    status = s.pop(val2);
    EXPECT_EQ(status, STACK_EMPTY);
}

TEST(StackTest, PushAndPop) {
    Stack<int, 5> s;
    int val;

    s.push(42);
    s.pop(val);

    EXPECT_EQ(val, 42);
}

TEST(StackTest, PushAndPeek)
{
    Stack<int, 20> s;
    int val;
    const int offset = 10;
    for (uint8_t i = 0; i < 20; i++)
    {
        s.push(i + offset);
    }

    s.peek(val, 0);
    EXPECT_EQ(val, 29);
}

TEST(StackTest, IsFull)
{
    Stack<int, 20> s;
    int val;
    const int offset = 10;
    StackStatus ret;
    for (uint8_t i = 0; i < 20; i++)
    {
        ret = s.push(i + offset);
        EXPECT_EQ(ret, STACK_OK);
    }
    EXPECT_EQ(s.isFull(), true);

}