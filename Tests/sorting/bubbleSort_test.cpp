#include "gtest/gtest.h"
#include "sorting/bubbleSort.h"

#define UNSORTED {2, 4, 2, 6, 1, 3}
#define SORTED {1, 2, 2, 3, 4, 6}

TEST(sorting_test, bubbleSortTest)
{
    std::array<int, 6> arrExpected = SORTED;
    std::array<int, 6> arr = UNSORTED;
    bubbleSort(arr.begin(), arr.end());
    EXPECT_EQ(arr, arrExpected);
}