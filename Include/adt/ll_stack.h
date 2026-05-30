#pragma once

#include <new>

enum LL_StackStatus
{
    LL_STACK_OK = 0,
    LL_STACK_FULL = 10,
    LL_STACK_EMPTY = 11,
    LL_STACK_OUT_OF_RANGE = 12,
};

template<typename T>
struct Node
{
    T value;
    Node *next;
};

template<typename T>
class LL_Stack
{
    public:
        LL_Stack();
        ~LL_Stack();
        LL_StackStatus push(const T &item);
        LL_StackStatus pop(T &item);
        LL_StackStatus peek(T &item, int idx);
        bool isFull();
        bool isEmpty();
    private:
        Node<T> *top;

};

template<typename T>
LL_Stack<T>::LL_Stack() : top(nullptr)
{

}

template<typename T>
LL_Stack<T>::~LL_Stack()
{
    T dummy;
    while (!isEmpty())
    {
        pop(dummy);
    }
}

template<typename T>
LL_StackStatus LL_Stack<T>::push(const T &item)
{
    Node<T> *n = new(std::nothrow) Node<T>;
    if (n == nullptr)
        return LL_STACK_FULL;
    
    n->next = top;
    n->value = item;
    top = n;
    return LL_STACK_OK;
}

template<typename T>
LL_StackStatus LL_Stack<T>::pop(T &item)
{
    if (top == nullptr)
        return LL_STACK_EMPTY;

    Node<T> *p;
    item = top->value;
    p = top;
    top = top->next;

    delete(p);
    return LL_STACK_OK;
}

template<typename T>
LL_StackStatus LL_Stack<T>::peek(T &item, int idx)
{
    Node<T> *p = top;
    for (int i = 0; (p != nullptr) && (i < idx); i++)
    {
        p = p->next;
    }

    if (idx < 0 || p == nullptr)
        return LL_STACK_OUT_OF_RANGE;
    item = p->value;
    return LL_STACK_OK;
}

template<typename T>
bool LL_Stack<T>::isFull()
{
    Node<T> *p = new(std::nothrow) Node<T>();
    if (!p)
    {
        return true;
    }
    else {
        delete p;
        return false;
    }
}

template<typename T>
bool LL_Stack<T>::isEmpty()
{
    return (top == nullptr);
}
