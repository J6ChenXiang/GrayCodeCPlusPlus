#include "dst/queue.h"
#include <iostream>

namespace dst {
    bool Queue::EnQueue(int data) {
        if ((rear + 1) % capability_ == front) {
            return false; // queue is full
        }
        array[rear] = data;
        rear = (rear + 1) % capability_;
        return true;
    }

    int Queue::DeQueue() {
        if (rear == front) {
            return false;
        }
        int pop = array[front];
        front = (front + 1) % capability_;
        return pop;
    }

    void Queue::Output() {
        int tmp = front;
        while (tmp != rear) {
            std::cout << array[tmp] << " , ";
            tmp = (tmp + 1) % capability_;
        }
        std::cout << std::endl;
    }

    void TestQueue() {
        Queue myQueue(5);
        myQueue.EnQueue(1);
        myQueue.EnQueue(2);
        myQueue.EnQueue(3);
        myQueue.EnQueue(4);
        std::cout << "after bunch of enqueue: " << std::endl;
        myQueue.Output();

        myQueue.DeQueue();
        myQueue.DeQueue();
        std::cout << "after dequeue: " << std::endl;
        myQueue.Output();
    }
}