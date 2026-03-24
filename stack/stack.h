#pragma once

#include <iostream>


enum StackStatus
{
    STACK_OK = 0,
    STACK_FULL = 10,
    STACK_EMPTY = 11,
    STACK_OUT_OF_RANGE = 12,
};

template <typename T, std::size_t N>
class Stack
{
    public:
        Stack();
        StackStatus push(const T &item);
        StackStatus pop(T &item);
        StackStatus peek(T &item, size_t idx);
        StackStatus isFull();
        StackStatus isEmpty();
        int count();
    private:
        int top;
        T buffer[N];

};
template <typename T, std::size_t N>
Stack<T, N>::Stack() : top(-1)
{

}

template <typename T, std::size_t N>
StackStatus Stack<T, N>::push(const T &item)
{
    if (top >= N - 1)
        return STACK_FULL;
    
    buffer[++top] = item;
    return STACK_OK;
}

template <typename T, std::size_t N>
StackStatus Stack<T, N>::pop(T &item)
{
    if (top < 0)
        return STACK_EMPTY;
    
    item = buffer[top--];
    return STACK_OK;
}

template <typename T, std::size_t N>
StackStatus Stack<T, N>::peek(T &item, size_t idx)
{
    if (top - idx <= -1)
        return STACK_OUT_OF_RANGE;
    
    item = buffer[top - idx];
    return STACK_OK;
}

template <typename T, std::size_t N>
StackStatus Stack<T, N>::isFull()
{
    if (top >= N - 1)
        return STACK_FULL;
    else
        return STACK_OK;
}

template <typename T, std::size_t N>
StackStatus Stack<T, N>::isEmpty()
{
    if (top < 0)
        return STACK_EMPTY;
    else
        return STACK_OK;
}

template <typename T, std::size_t N>
int Stack<T, N>::count()
{
    return top + 1;
}
