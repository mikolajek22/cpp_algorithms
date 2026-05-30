#pragma once

template <typename Iterator>
void bubbleSort(Iterator begin, Iterator end)
{
    
    for (auto i = begin; i != end; ++i)
    {
        bool swapped = false;
        for (auto j = begin; j != end - 1; ++j)
        {
            if (*j > *(j + 1))
            {
                std::swap(*j, *(j + 1));
                swapped = true;
            }
        }
        if (!swapped) return;
    }
}