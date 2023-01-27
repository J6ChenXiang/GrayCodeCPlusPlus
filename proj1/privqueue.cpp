#include "dst/privqueue.h"
#include <iostream>

namespace dst {
    void PriQueue::EnQueue(int data) {
        array_.push_back(data);
        arrSize_++;
        UpAdjust();
    }

    int PriQueue::DeQueue() {
        int ret = array_[0];
        array_[0] = array_[arrSize_ - 1];
        array_.pop_back();
        arrSize_--;
        DownAdjust();
        return ret;
    }

    void PriQueue::UpAdjust() {
        size_t childIdx = arrSize_ - 1;
        size_t parentIdx = (childIdx - 1) / 2;
        int tmp = array_[childIdx];
        while (childIdx > 0 && tmp < array_[parentIdx]) {
            array_[childIdx] = array_[parentIdx];
            childIdx = parentIdx;
            parentIdx = (parentIdx - 1) / 2;
        }
        array_[childIdx] = tmp;
    }

    void PriQueue::DownAdjust() {
        if (arrSize_ == 0) {
            return ;
        }
        size_t parentIdx = 0;
        size_t childIdx = parentIdx * 2 + 1;
        int tmp = array_[parentIdx];
        while (childIdx < arrSize_) {
            if ((childIdx + 1) < arrSize_ && array_[childIdx] > array_[childIdx + 1]) {
                childIdx++;
            }
            if (tmp < array_[childIdx]) {
                break;
            }
            array_[parentIdx] = array_[childIdx];
            parentIdx = childIdx;
            childIdx = childIdx * 2 + 1;
        }
        array_[parentIdx] = tmp;
    }

    void PriQueue::Output() {
        for (auto& item : array_) {
            std::cout << "val: " << item << " , ";
        }
        std::cout << std::endl;
    }

    void TestBiHeapPrivQ() {
        PriQueue priQ;
        priQ.EnQueue(2);
        priQ.EnQueue(1);
        priQ.EnQueue(6);
        priQ.EnQueue(4);
        
        priQ.Output();

        for(int i = 0; i < 4; i++) {
            std::cout << "out: " << priQ.DeQueue() << std::endl;
        }
    }
}