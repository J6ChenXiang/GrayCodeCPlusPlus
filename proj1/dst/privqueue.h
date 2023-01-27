#pragma once
#include <vector>

namespace dst {
    class PriQueue {
    private:
        std::vector<int> array_;
        size_t arrSize_ {0};
    public:
        PriQueue() = default;
        void EnQueue(int data);
        int DeQueue();
        void Output();
    private:
        void UpAdjust();
        void DownAdjust();
    };

    void TestBiHeapPrivQ();
}