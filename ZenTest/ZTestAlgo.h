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

// A.size() > B.size()
int findSubArray(std::vector<int>& A, std::vector<int>& B)
{
    int i = 0;
    std::vector<int> cur_sub;
    std::vector<int> largest_sub;
    
    while(i < A.size())
    {
        bool isSequence = false;
        
        for(int j = 0; j < B.size(); ++j)
        {
            if(A[i] == B[j])
            {
                cur_sub.push_back(A[i]);
                isSequence = true;
                i++;
            }
            else if (isSequence && A[i] != B[j])
            {
                if(cur_sub.size() > largest_sub.size())
                {
                    largest_sub = cur_sub;
                }
                
                isSequence = false;
            }
        }
        
        i -= cur_sub.size();
        i++;
    }
    
    return largest_sub.size();
}

void remove_duplicates(std::vector<int>& arr)
{
    std::vector<int>::iterator it = arr.begin();
                                                
    int prev_value = -1;
    while(it != arr.end())
    {
        if(prev_value == (*it))
        {
            it = arr.erase(it);
        }
        else
        {
            prev_value = (*it);
            it++;
        }
    }
}

void to_console(const std::vector<int>& vec)
{
    std::for_each(vec.begin(), vec.end(), [](int i) { std::cout << i << " "; });
    std::cout << std::endl;
}

TEST(Dummy, Dummy)
{
    std::vector<int> A = {8, 1, 2, 2, 3};
    
    std::sort(A.begin(), A.end());
    to_console(A);
    remove_duplicates(A);
    to_console(A);
}

#endif /* ZTestAlgo_h */
