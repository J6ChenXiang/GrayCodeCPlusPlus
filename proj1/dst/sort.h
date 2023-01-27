#pragma once
#include <iostream>

namespace dst {
    template<class Func>
    void Sort(Func func, int* array, size_t len) {
        func(array, len);
        std::cout << "after sort: " << std::endl;         
        for (size_t i = 0; i < len; i++) {
            std::cout << array[i] << " , ";
        }
        std::cout << std::endl;
    }

    void TestBubbleSort();
    void TestQuickSort();
}