#ifndef ZSort_h
#define ZSort_h

#include <vector>
#include <algorithm>
#include <cstdio>

namespace Zen
{
    template <std::size_t SIZE, class T>
    std::size_t array_size(const T(&)[SIZE])
    {
        return SIZE;
    }

    template<typename T>
    void swap(T& t1, T& t2)
    {
        T temp = std::move(t1);
        t1 = std::move(t2);
        t2 = std::move(temp);
    }

    template<typename T>
    int partition(T* array, int low, int high)
    {
        const T pivot = array[high];
        int i = low;
        
        for(int j = low; j < high; ++j)
        {
            if(array[j] < pivot)
            {
                swap(array[j], array[i]);
                i++;
            }
        }
        
        swap(array[i], array[high]);
        
        return i;
    }

    template<typename T>
    void merge(const std::vector<T>& left, const std::vector<T>& right, std::vector<T>& res)
    {
        int i = 0 , j = 0;
        
        while( i < left.size() && j < right.size())
        {
            if(left[i] < right[j])
            {
                res.push_back(left[i]);
                i++;
            }
            else
            {
                res.push_back(right[j]);
                j++;
            }
        }
        
        while( i < left.size())
        {
            res.push_back(left[i]);
            i++;
        }
        
        while( j < right.size())
        {
            res.push_back(right[j]);
            j++;
        }
    }

    template<typename T>
    void merge_sort(std::vector<T>& array)
    {
        if(array.size() <= 1)
        {
            return;
        }
        
        std::vector<T> right;
        std::vector<T> left;
        
        const int size = static_cast<int>(array.size());
        
        for(int i = 0 ; i < size / 2; ++i)
        {
            left.push_back(array[i]);
        }
        
        for(int j = size / 2; j < size; ++j)
        {
            right.push_back(array[j]);
        }
        
        array.clear();
        merge_sort(left);
        merge_sort(right);
        merge(left,right,array);
    }

    template<typename T>
    void insert_sort(std::vector<T>& array)
    {
        for(int i = 1; i < array.size(); ++i)
        {
            int key = array[i];
            int j = 0;
            
            for(j = i - 1; j >= 0 && array[j] > key; --j)
            {
                array[j + 1] = array[j];
            }
            
            array[j + 1] = key;
        }
    }

    template<typename T>
    void select_sort(std::vector<T>& array)
    {
        for(int i = 0; i < array.size() - 1; ++i)
        {
            int key = i;
            for(int j = i + 1; j < array.size(); ++j)
            {
                if(array[j] < array[key])
                {
                    key = j;
                }
            }
            
            if(key > i)
            {
                swap(array[key], array[i]);
            }
        }
    }

    template<typename T>
    void bubble_sort(std::vector<T>& array)
    {
        for(int i = 0 ; i < array.size(); ++i)
        {
            for(int j = 1; j < array.size() - i; ++j)
            {
                if(array[j - 1] > array[j])
                {
                    swap(array[j - 1], array[j]);
                }
            }
        }
    }

    template<typename T>
    void quick_sort(T* array, int left, int right)
    {
        if(left < right)
        {
            int pi = partition(array, left, right);
            
            quick_sort(array, left, pi - 1);
            quick_sort(array, pi + 1, right);
        }
    }
}

#endif //ZSort
