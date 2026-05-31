#pragma once


template <typename Iterator>
void selectionSort(Iterator begin, Iterator end)
{
    for (auto i = begin; i != (end - 1); ++i)
    {
        auto minIt = i;
        for (auto j = i; j != end; ++j)
        {
            if (*j < *minIt)
                minIt = j;
        }
        std::swap(*i, *minIt);
    }
}