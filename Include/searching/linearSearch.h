#pragma once

template <typename Iterator, typename T>
Iterator linearSearch(Iterator begin, Iterator end, const T &value)
{
    for (auto it = begin; it != end; ++it)
    {
        if (*it == value)
            return it;
    }
    return end;
}