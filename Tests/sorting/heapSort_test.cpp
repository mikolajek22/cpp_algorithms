#include "gtest/gtest.h"
#include "sorting/heapSort.h"

#define UNSORTED {2, 4, 2, 6, 1, 3}
#define SORTED {1, 2, 2, 3, 4, 6}

TEST(sorting_test, heapSortTest)
{
    std::array<int, 15> arr = {1, 6, 3, 2, 4, 5, 1, 6, 3, 5, 2, 6, 3, 5, 2};
    heapSort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << ", ";
    }
}