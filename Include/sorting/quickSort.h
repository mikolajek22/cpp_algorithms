#pragma once

template <typename Iterator>
static Iterator partition(Iterator begin, Iterator end);

template <typename Iterator>
void quickSort(Iterator begin, Iterator end)
{
    if (std::distance(begin, end) <= 1)
        return;
    auto p = partition(begin, end);
    quickSort(begin, p);
    quickSort(p + 1, end);
}

template <typename Iterator>
static Iterator partition(Iterator begin, Iterator end)
{
    Iterator pivot = end - 1;
    Iterator boundary = begin;

    for (Iterator i = begin; i != end - 1; ++i)
    {
        if (*i <= *pivot)
        {
            std::swap(*i, *boundary);
            ++boundary;
        }
    }
    std::swap(*boundary, *(end - 1));
    return boundary;
}


