#pragma once

enum class QueueStatus {
    QUEUE_OK = 0,
    QUEUE_FULL = 1,
    QUEUE_EMPTY = 2,
};

template <typename T, size_t N>
class Queue
{
    public:
        Queue();
        QueueStatus push(const T &item);
        QueueStatus pop(T &item);
        bool isEmpty();
        bool isFull();
        QueueStatus flush();
    private:
        T q[N];
        size_t tail;
        size_t head;
        size_t count;
};

template <typename T, size_t N>
Queue<T, N>::Queue() : head(0), tail(0), count(0)
{
    
}

template <typename T, size_t N>
QueueStatus Queue<T, N>::push(const T &item)
{
    if (!isFull() && head < N)
    {
        q[head++] = item;
        count++;
        return QueueStatus::QUEUE_OK;
    }
    return QueueStatus::QUEUE_FULL;
}

template <typename T, size_t N>
QueueStatus Queue<T, N>::pop(T &item)
{
    if (!isEmpty() && tail < N)
    {
        item = q[tail++];
        count--;
        return QueueStatus::QUEUE_OK;
    }
    return QueueStatus::QUEUE_EMPTY;
}

template <typename T, size_t N>
bool Queue<T, N>::isEmpty()
{
    return (count == 0);
}


template <typename T, size_t N>
bool Queue<T, N>::isFull()
{
    return (count == N);
}

template <typename T, size_t N>
QueueStatus Queue<T, N>::flush()
{
    q={};
    head = tail = count = 0;
    return QueueStatus::QUEUE_OK;
}
