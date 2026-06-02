#include <gtest/gtest.h>
#include <chrono>
#include <array>
#include <fstream>
#include <random>


#include "sorting/bubbleSort.h"
#include "sorting/insertionSort.h"
#include "sorting/mergeSort.h"
#include "sorting/selectionSort.h"
#include "sorting/quickSort.h"
#include "sorting/heapSort.h"


#define RANDOM_SEED 42

std::vector<int> generateArray(size_t n)
{
    std::vector<int> vect(n);
    /* Set rand seed for random generator*/
    std::mt19937 rng(RANDOM_SEED);
    /* int distribution */
    std::uniform_int_distribution<int> dist(0, 1000000);
    for (auto &item : vect)
    {
        item = dist(rng);
    }
    return vect;
}

class TimeComparament : public ::testing::Test
{
    protected:
    std::ofstream file;
    void SetUp() override
    {
        file.open("../Tests/sorting/data/sorting_results.csv", std::ios::out | std::ios::trunc);
    }
    void TearDown() override
    {
        file.close();
    }   

};
void sortAndMeasure(size_t n, std::ofstream &file)
{
    auto vectOrg = generateArray(n);

    auto vect = vectOrg;
    auto start = std::chrono::high_resolution_clock::now();
    bubbleSort(vect.begin(), vect.end());
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    file << n << ",bubble," << duration.count() << "\n";

    vect = vectOrg;
    start = std::chrono::high_resolution_clock::now();
    insertionSort(vect.begin(), vect.end());
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    file << n << ",insertion," << duration.count() << "\n";

    vect = vectOrg;
    start = std::chrono::high_resolution_clock::now();
    mergeSort(vect.begin(), vect.end());
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    file << n << ",merge," << duration.count() << "\n";

    vect = vectOrg;
    start = std::chrono::high_resolution_clock::now();
    quickSort(vect.begin(), vect.end());
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    file << n << ",quick," << duration.count() << "\n";

    vect = vectOrg;
    start = std::chrono::high_resolution_clock::now();
    heapSort(vect.begin(), vect.end());
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    file << n << ",heap," << duration.count() << "\n";

    vect = vectOrg;
    start = std::chrono::high_resolution_clock::now();
    selectionSort(vect.begin(), vect.end());
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    file << n << ",selection," << duration.count() << "\n";

}

TEST_F(TimeComparament, sortingTimeComparament)
{
    file << "n,algorithm,time_us\n";
    for (size_t n : {100, 200 , 500, 1000, 2000, 5000, 10000})
        sortAndMeasure(n, file);
}