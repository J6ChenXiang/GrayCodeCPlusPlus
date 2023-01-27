#pragma once

namespace dst {
    class Queue {
    private:
        int capability_ {0};
        int* array {nullptr};
        int front {0};
        int rear {0};
    public:
        Queue(int capability):capability_(capability) {
            array = new int[capability];
        }
        bool EnQueue(int data);
        int DeQueue();
        void Output();
        ~Queue() {
            delete [] array;
            array = nullptr;
        }
    };

    void TestQueue();
}