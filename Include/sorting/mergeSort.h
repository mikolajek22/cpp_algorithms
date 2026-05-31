#pragma once

template <typename Iterator>
static void merge(Iterator begin, Iterator mid, Iterator end);

template <typename Iterator>
void mergeSort(Iterator begin, Iterator end)
{
     /* if single element end recursion (1 cuz end's pointing behind the arr)*/
    if (std::distance(begin, end) <= 1)
        return;

    /* Middle pos */
    Iterator mid = begin + (end - begin) / 2;
    mergeSort(begin, mid);
    mergeSort(mid, end);
    merge(begin, mid, end);
}

template <typename Iterator>
static void merge(Iterator begin, Iterator mid, Iterator end)
{
    /* get type sorted array */
    using valueType = typename std::iterator_traits<Iterator>::value_type;

    /* lengths for temporary arrays */
    size_t n_left = std::distance(begin, mid);
    size_t n_right = std::distance(mid, end);

    /* temporary arrays */
    std::vector<valueType> vect_left(n_left);
    std::vector<valueType> vect_right(n_right);

    /* copy to temp arrays */
    size_t idx = 0;
    for (auto i = begin; i != mid; ++i)
    {
        vect_left[idx++] = *i;
    }
    idx = 0;
    for (auto i = mid; i != end; ++i)
    {
        vect_right[idx++] = *i;
    }

    size_t i = 0, j = 0;
    Iterator out = begin;

    while (i < n_left && j < n_right)
    {
        if (vect_left[i] <= vect_right[j])
        {
            *out = vect_left[i];
            ++out;
            ++i;
        }
        else
        {
            *out = vect_right[j];
            ++out;
            j++;
        }
    }

    /* complement from left arr */
    while (i < n_left)
    {
        *out = vect_left[i];
        ++out;
        ++i;
    }
    /* complement from right arr */
    while (j < n_right)
    {
        *out = vect_right[j];
        ++out;
        ++j;
    }
}