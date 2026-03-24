#pragma once


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
    LL_Stack    ();
        LL_StackStatus push(T &item);
        LL_StackStatus pop(T &item);
        LL_StackStatus peek(T &item, int idx);
        LL_StackStatus isFull();
        LL_StackStatus isEmpty();
    private:
        Node *top;

};

template<typename T>
LL_Stack<T>::LL_Stack() : top(nullptr)
{

}

template<typename T>
LL_StackStatus LL_Stack<T>::push(T &item)
{
    Node *n = new Node;
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

    Node *p;
    item = top->value;
    p = top;
    top = top->next;

    delete(p);
    return LL_STACK_OK;
}

template<typename T>
LL_StackStatus LL_Stack<T>::peek(T &item, int idx)
{
    Node *p = top;
    for (int i = 0; (p != nullptr) && (i < idx - 1); i++)
    {
        p = p->next;
    }

    if (p == nullptr)
        return LL_STACK_OUT_OF_RANGE;
    item = p->value;
    return LL_STACK_OK;
}

template<typename T>
LL_StackStatus LL_Stack<T>::isFull()
{
    Node *p = new Node();
    if (!p)
    {
        return LL_STACK_FULL;
    }
    else {
        delete p;
        return LL_STACK_OK;
    }
}

template<typename T>
LL_StackStatus LL_Stack<T>::isEmpty()
{
    return (top == nullptr) ? LL_STACK_EMPTY : LL_STACK_OK;
}
