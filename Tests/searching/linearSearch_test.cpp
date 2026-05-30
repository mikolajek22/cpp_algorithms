#include "gtest/gtest.h"
#include "searching/linearSearch.h"

#include <random>
#include <array>
#include <list>

#define DEFAULT_TABLE_VALUES {5, 2, 3, 1, 6}

TEST(searching_test, dataTypesTest)
{
    const uint8_t idx = 3;
    std::array<int, 5> arr = DEFAULT_TABLE_VALUES;
    std::array<int, 5>::iterator retArr = linearSearch(arr.begin(), arr.end(), 1);
    EXPECT_EQ(retArr - arr.begin(), idx);

    std::vector<int> vect = DEFAULT_TABLE_VALUES;
    std::vector<int>::iterator retVect = linearSearch(vect.begin(), vect.end(), 1);
    EXPECT_EQ(retVect - vect.begin(), idx);

    std::list<int> l = DEFAULT_TABLE_VALUES;
    std::list<int>::iterator retL = linearSearch(l.begin(), l.end(), 1);
    EXPECT_EQ(std::distance(l.begin(), retL), idx);
}