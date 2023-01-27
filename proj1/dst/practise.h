#pragma once
#include "linklist.h"
#include <stack>

namespace dst {
    void TestListLoop();

    class MinStack {
    private:
        std::stack<int> minStack;
        std::stack<int> mainStack;
    public:
        void Push(int data);
        int Pop();
        int GetMin(); 
    };

    void TestMinStack();

    class StackQ {
    private:
        std::stack<int> mainStack;
        std::stack<int> helpStack;
    public:
        void EnQueue(int data);
        int DeQueue();
    };

    void TestStackQ();

    void TestGcdUse();

    void TestPowerOfTwo();

    void TestDeleteNGetMin();

    void TestNextPermutation();
}