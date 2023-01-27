#include "dst/sort.h"
#include <vector>

namespace dst {
    void BubbleSort(int* array, size_t len) {
        for (int i = 0; i < len - 1; i++) {
            for (int j = 0; j < len - i - 1; j++) {
                if (array[j] > array[j+1]) {
                    int tmp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = tmp;
                }
            }
        }
    }

    size_t Partition(int* array, size_t startIdx, size_t endIdx) {
        auto left = startIdx;
        auto right = endIdx;
        int pivot = array[startIdx];
        while (left != right) {
            while (left < right && pivot < array[right]) {
                right--;
            }

            while (left < right && pivot >= array[left]) {
                left++;
            }
            if (left < right) {
                int tmp = array[left];
                array[left] = array[right];
                array[right] = tmp;
            }
        }

        array[startIdx] = array[left];
        array[left] = pivot;
        return left;
    }

    void QuickSortDFS(int* array, size_t startIdx, size_t endIdx) {
        if (startIdx >= endIdx) {
            return ;
        }
        size_t partition = Partition(array, startIdx, endIdx);
        QuickSortDFS(array, startIdx, partition - 1);
        QuickSortDFS(array, partition+ 1, endIdx);
    }

    void QuickSort(int *array, size_t len) {
        QuickSortDFS(array, 0, len - 1);
    }

    void TestBubbleSort() {
        std::vector<int> array = {2, 1, 5, 3, 10, 8};
        Sort(BubbleSort, array.data(), array.size());
    }

    void TestQuickSort() {
        std::vector<int> array = {2, 1, 5, 3, 10, 8};
        Sort(QuickSort, array.data(), array.size());
    }

}