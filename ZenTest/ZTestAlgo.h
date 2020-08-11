#ifndef ZTestAlgo_h
#define ZTestAlgo_h

#include "gtest/gtest.h"

#include <vector>
#include <algorithm>

#include "ZAlgo/ZSort.h"
#include "ZAlgo/ZSearch.h"

TEST(Sort, Select_Sort)
{
    std::vector<int> array = { 100, -3, 10, 15, 34, 82, 91, -1000, 9, 0};
    
    std::vector<int> expected_res = array;
    std::sort(expected_res.begin(), expected_res.end());
    
    Zen::select_sort<int>(array);
    
    EXPECT_TRUE(array == expected_res);
}

TEST(Sort, Insertion_Sort)
{
    std::vector<int> array = { 100, -3, 10, 15, 34, 82, 91, -1000, 9, 0};
    
    std::vector<int> expected_res = array;
    std::sort(expected_res.begin(), expected_res.end());
    
    Zen::insert_sort<int>(array);
    
    EXPECT_TRUE(array == expected_res);
}

TEST(Sort, Merge_Sort)
{
    std::vector<int> array = { 100, -3, 10, 15, 34, 82, 91, -1000, 9, 0};
    
    std::vector<int> expected_res = array;
    std::sort(expected_res.begin(), expected_res.end());
    
    Zen::merge_sort<int>(array);
    
    EXPECT_TRUE(array == expected_res);
}

TEST(Sort, Bubble_Sort)
{
    std::vector<int> array = {100, -3, 10, 15, 34, 82, 91, -1000, 9, 0};
    
    std::vector<int> expected_res = array;
    std::sort(expected_res.begin(), expected_res.end());
    
    Zen::bubble_sort<int>(array);
    
    EXPECT_TRUE(array == expected_res);
}

TEST(Sort, Quick_Sort)
{
    std::vector<int> array = {100, -3, 10, 15, 34, 34, 34, -1000, 9, 0};
    const int length = static_cast<int>(array.size());
    
    std::vector<int> expected_res = array;
    std::sort(expected_res.begin(), expected_res.end());
    
    Zen::quick_sort(array.data(), 0, length - 1);
    
    EXPECT_TRUE(array == expected_res);
}

TEST(Search, Binary_Search)
{
    std::vector<int> array = {100, -3, 10, 15, 34, 82, 91, -1000, 9, 0};
    
    Zen::select_sort(array);
    std::size_t index = Zen::binary_search(array.data(), array.size(), 9);
    
    EXPECT_TRUE(array[index] == 9);
}

#endif /* ZTestAlgo_h */
