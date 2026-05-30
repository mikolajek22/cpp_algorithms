#pragma once

#include <stdexcept>
#include <utility>

using namespace std;

enum QueueStatus
{
    QUEUE_OK,
    QUEUE_EMPTY,
    QUEUE_FULL,
};

template <typename T>
class Queue 
{

    private:
        int head;
        int tail;
        int size;
        int count;
        T *Q;
    public:
        Queue(int size);
        Queue(const Queue &other);
        Queue(Queue &&other) noexcept;
        ~Queue();

        QueueStatus dequeue(T &value);
        QueueStatus enqueue(const T &value);
        QueueStatus enqueue(T &&value);
        QueueStatus isEmpty() const;

        Queue& operator=(Queue&& other) noexcept;
        Queue& operator=(const Queue &other);
};

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& other)
{
    if (this != &other)
    {
        delete[] Q;
        head = other.head;
        tail = other.tail;
        size = other.size;
        count = other.count;
        Q = new T[size];

        for (int i = 0; i < size; i++)
            Q[i] = other.Q[i];
    }
    

    return *this;
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue&& other) noexcept
{
    if (this != &other)
    {
        delete[] Q;

        head = other.head;
        tail = other.tail;
        size = other.size;
        count = other.count;
        Q = other.Q;

        other.Q = nullptr;
        other.size = 0;
        other.count = 0;
    }
    return *this;
}
template <typename T>
Queue<T>::Queue(const Queue &other) : head(other.head), tail(other.tail), count(other.count), size(other.size)
{
    Q = new T[this->size];
    for (int i = 0; i < other.size; i++)
    {
        this->Q[i] = other.Q[i];
    }
}

template <typename T>
Queue<T>::Queue(int size) : head(0), tail(0), Q(nullptr), count(0)
{
    if (size <= 0)
        throw invalid_argument("Queue size must be bigger than 0!");

    this->size = size;
    Q = new T[size];
}

template <typename T>
Queue<T>::~Queue()
{
    delete[] Q;
}
template <typename T>
Queue<T>::Queue(Queue &&other) noexcept 
            : head(other.head), size(other.size), tail(other.tail), Q(other.Q), count(other.count)
{
    other.Q = nullptr;
    other.size = 0;
    other.count = 0;
}

template <typename T>
QueueStatus Queue<T>::dequeue(T &value)
{
    if (count != 0)
    {
        value = Q[tail++];
        tail = tail % size;
        count--;
        return QUEUE_OK;
    }
    else
    {
        return QUEUE_EMPTY;
    }
}

template <typename T>
QueueStatus Queue<T>::enqueue(const T &value)
{

    if (count != size)
    {
        Q[head++] = value;
        head = head % size;
        count++;
        return QUEUE_OK;
    }
    else
    {
        return QUEUE_FULL;
    }
}

template <typename T>
QueueStatus Queue<T>::enqueue(T &&value)
{

    if (count != size)
    {
        Q[head++] = std::move(value);
        head = head % size;
        count++;
        return QUEUE_OK;
    }
    else
    {
        return QUEUE_FULL;
    }
}


template <typename T>
QueueStatus Queue<T>::isEmpty() const
{
    return (count == 0) ? QUEUE_EMPTY : QUEUE_OK;
}