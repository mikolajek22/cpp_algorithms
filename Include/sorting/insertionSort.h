#pragma once

template <typename Iterator>
void insertionSort(Iterator begin, Iterator end)
{
    for (auto i = begin + 1; i != end; ++i)
    {
        if (*i >= *(i - 1))
            continue;
        
        for (auto j = i; j != begin && *j < *(j - 1); --j)
        {
            std::swap(*j, *(j - 1));
        }
    }
}