#pragma once

/**
 * @brief Only sorted arrays input
 */

template <typename Iterator, typename T>
Iterator binarySearch(Iterator begin, Iterator end, const T &value)
{
    
    while (begin != end)
    {
        auto mid = begin + (end - begin) / 2;

        if (value == *mid)
            return mid;
        else if (value > *mid)
            begin = mid + 1;
        else
            end = mid;
    }
    return end;
}
