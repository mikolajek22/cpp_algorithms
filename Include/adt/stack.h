#pragma once


enum StackStatus
{
    STACK_OK = 0,
    STACK_FULL = 10,
    STACK_EMPTY = 11,
    STACK_OUT_OF_RANGE = 12,
};

template <typename T, size_t N>
class Stack
{
    public:
        Stack();
        StackStatus push(const T &item);
        StackStatus pop(T &item);
        StackStatus peek(T &item, int idx);
        bool isFull();
        bool isEmpty();
        size_t count();
    private:
        int top;
        T buffer[N];

};
template <typename T, size_t N>
Stack<T, N>::Stack() : top(-1)
{

}

template <typename T, size_t N>
StackStatus Stack<T, N>::push(const T &item)
{
    if (top >= static_cast<int>(N) - 1)
        return STACK_FULL;
    
    buffer[++top] = item;
    return STACK_OK;
}

template <typename T, size_t N>
StackStatus Stack<T, N>::pop(T &item)
{
    if (top < 0)
        return STACK_EMPTY;
    
    item = buffer[top--];
    return STACK_OK;
}

template <typename T, size_t N>
StackStatus Stack<T, N>::peek(T &item, int idx)
{
    if (idx < 0 || top - idx <= -1)
        return STACK_OUT_OF_RANGE;
    
    item = buffer[top - idx];
    return STACK_OK;
}

template <typename T, size_t N>
bool Stack<T, N>::isFull()
{
    return (top >= static_cast<int>(N) - 1);
}

template <typename T, size_t N>
bool Stack<T, N>::isEmpty()
{
    return (top < 0);
}

template <typename T, size_t N>
size_t Stack<T, N>::count()
{
    return top + 1;
}
