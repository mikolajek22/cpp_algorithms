#pragma once

template <typename Iterator>
static void heapify(Iterator begin, Iterator end, Iterator largest);

template <typename Iterator>
void heapSort(Iterator begin, Iterator end)
{
    int n = std::distance(begin, end);
    /* create max binary tree */
    for (int i = n/2 - 1; i >= 0; --i)
        heapify(begin, end, begin + i);

    for (Iterator last = end - 1; last != begin; --last)
    {
        std::swap(*begin, *last);
        heapify(begin, last, begin);
    }
    
}
template <typename Iterator>
static void heapify(Iterator begin, Iterator end, Iterator root)
{
    size_t dist = std::distance(begin, root);

    Iterator winner = root;
    Iterator left = begin + 2 * dist + 1;
    Iterator right = begin + 2 * dist + 2;
    

    if (std::distance(left, (end - 1)) >= 0 && *left > *winner)
        winner = left;
    if (std::distance(right, (end - 1)) >= 0 && *right > *winner)
        winner = right;
    
    if (winner != root)
    {
        std::swap(*winner, *root);
        heapify(begin, end, winner);
    }
}