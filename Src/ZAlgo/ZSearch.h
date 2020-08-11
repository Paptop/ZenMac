#ifndef ZSearch_h
#define ZSearch_h

#include <vector>
#include <cstdio>

namespace Zen
{
    template<std::size_t SIZE, typename T>
    constexpr std::size_t size_of_array(const T(&)[SIZE])
    {
        return SIZE;
    }

    template<typename T>
    std::size_t binary_search(T* array, std::size_t size, T elem)
    {
        std::size_t right = size - 1;
        std::size_t left = 0;
        
        while(left <= right)
        {
            std::size_t mid = left + (right - left) / 2;
            
            if(array[mid] == elem)
            {
                return mid;
            }
            
            if(array[mid] > elem)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        
        return -1;
    }
}

#endif /* ZSearch_h */
