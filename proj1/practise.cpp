#include "dst/practise.h"
#include <iostream>
#include <string>
#include <vector>

namespace dst {
    bool IsLinkListHasLoop(const Node* head) {
        if (head == nullptr) {
            return false;
        }
        const Node* p = head;
        const Node* q = head;
        while (q != nullptr && q->next_ != nullptr) {
            p = p->next_;
            q = q->next_->next_;
            if (p == q) {
                return true;
            }
        }
        return false;
    }

    Node* CreateLoopList() {
        Node* head = new Node(0);
        Node* node1 = new Node(1);
        Node* node2 = new Node(2);
        Node* node3 = new Node(3);
        Node* node4 = new Node(4);
        Node* node5 = new Node(5);
        head->next_ = node1;
        node1->next_ = node2;
        node2->next_ = node3;
        node3->next_ = node4;
        node4->next_ = node5;
        node5->next_ = node2;
        return head;
    }

    Node* CreateWithoutLoopList() {
        Node* head = new Node(0);
        Node* node1 = new Node(1);
        Node* node2 = new Node(2);
        Node* node3 = new Node(3);
        Node* node4 = new Node(4);
        Node* node5 = new Node(5);
        head->next_ = node1;
        node1->next_ = node2;
        node2->next_ = node3;
        node3->next_ = node4;
        node4->next_ = node5;
        return head;
    }

    int GetLoopLength(Node* head) {
        if (head == nullptr) {
            return 0;
        }
        Node* slowP = head;
        Node* quickQ = head;
        bool isStartCount = false;
        int count = 0;
        while (quickQ != nullptr && quickQ->next_ != nullptr) {
            slowP = slowP->next_;
            quickQ = quickQ->next_->next_;
            if (slowP == quickQ) {
                if (!isStartCount) {
                    isStartCount = true;
                } else {
                    break;
                }
            }
            if (isStartCount) {
                count++;
            }
        }
        return isStartCount ? count : 0;
    }

    Node* GetLoopStartNode(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        Node* slowP = head;
        Node* quickQ = head;
        bool isStartGet = false;
        while (quickQ != nullptr && quickQ->next_ != nullptr) {
            if (!isStartGet) {
                slowP = slowP->next_;
                quickQ = quickQ->next_->next_;
            } else {
                slowP = slowP->next_;
                quickQ = quickQ->next_;
            }
            if (slowP == quickQ) {
                if (!isStartGet) {
                    isStartGet = true;
                    slowP = head;
                } else {
                    break;
                }
            }
        }
        return isStartGet ? slowP : nullptr;
    }

    void TestListLoop() {
        Node* loopHead = CreateLoopList();
        Node* noLoopHead = CreateWithoutLoopList();
        if (IsLinkListHasLoop(loopHead)) {
            std::cout << "loopHead has loop " << std::endl;
            std::cout << "Get loop Len: " << GetLoopLength(loopHead) << std::endl;
            std::cout << "Get loop Start Node Val: " << GetLoopStartNode(loopHead)->data_ << std::endl;
        }
        if (!IsLinkListHasLoop(noLoopHead)) {
            std::cout << "noLoop Head has no loop" << std::endl;
            std::cout << "Get noloop Len: " << GetLoopLength(noLoopHead) << std::endl;
        }
        Node* tmp = loopHead;
        for(int i = 0; i < 6; i++) {
            loopHead = loopHead->next_;
            delete tmp;
            tmp = loopHead;
        }
        tmp = noLoopHead;
        while (tmp != nullptr) {
            noLoopHead = noLoopHead->next_;
            delete tmp;
            tmp = noLoopHead;
        }
        tmp = nullptr;
    }

    void MinStack::Push(int data) {
        if (minStack.empty() || minStack.top() > data) {
            minStack.push(data);
        }
        mainStack.push(data);
    }

    int MinStack::Pop() {
        if (mainStack.empty()) {
            std::cout << "is empty, can not pop right" << std::endl;
            return -1;
        }
        int ret = mainStack.top();
        mainStack.pop();
        if (ret == minStack.top()) {
            minStack.pop();
        }
        return ret;
    }

    int MinStack::GetMin() {
        return minStack.top();
    }

    void TestMinStack() {
        MinStack minStack;
        minStack.Push(2);
        minStack.Push(4);
        std::cout << "after first push, Min is: " << minStack.GetMin() << std::endl;
        minStack.Push(1);
        std::cout << "after second push, Min is: " << minStack.GetMin() << std::endl;
        minStack.Pop();
        std::cout << "after pop, minStack is: " << minStack.GetMin() << std::endl;
    }

    void StackQ::EnQueue(int data) {
        mainStack.push(data); 
    }

    int StackQ::DeQueue() {
        if (mainStack.empty() && helpStack.empty()) {
            return -1;
        }
        if (!helpStack.empty()) {
            int ret = helpStack.top();
            helpStack.pop();
            return ret;
        }
        while (!mainStack.empty()) { // helpStack is empty, transfer once
            int item = mainStack.top();
            mainStack.pop();
            helpStack.push(item);
        }
        int ret = helpStack.top();
        helpStack.pop();
        return ret;
    }

    void TestStackQ() {
        StackQ stackQ;
        stackQ.EnQueue(1);
        stackQ.EnQueue(2);
        stackQ.EnQueue(3);
        stackQ.EnQueue(4);
        std::cout << "first out is: " << stackQ.DeQueue() << std::endl;
        stackQ.EnQueue(5);
        stackQ.EnQueue(6);
        stackQ.EnQueue(7);
        stackQ.EnQueue(8);
        stackQ.EnQueue(9);
        std::cout << "second out is: " << stackQ.DeQueue() << std::endl;
        std::cout << "third out is: " << stackQ.DeQueue() << std::endl;
        std::cout << "fourth out is: " << stackQ.DeQueue() << std::endl;
        std::cout << "fifth out is: " << stackQ.DeQueue() << std::endl;
        std::cout << "sixth out is: " << stackQ.DeQueue() << std::endl;
    }

    int GetGcdRet(int a, int b) {
        if (a == b) {
            return a;
        }
        if (((a & 1) == 0) && ((b & 1) != 0)) {
            return GetGcdRet(a >> 1, b);
        }
        if (((a & 1) != 0) && ((b & 1) == 0)) {
            return GetGcdRet(a, b >> 1);
        }
        if (((a & 1) == 0) && ((b & 1) == 0)) {
            return GetGcdRet(a >> 1, b >> 1) << 1;
        }
        int big = a > b ? a : b;
        int small = a > b ? b : a;
        return GetGcdRet(big - small, small);
    }

    void TestGcdUse() {
        std::cout << GetGcdRet(10, 25) << std::endl;
        std::cout << GetGcdRet(18, 3) << std::endl;
        std::cout << GetGcdRet(27, 9) << std::endl;
    }

    bool IsTwoPower(int n) {
        return (n & (n -1)) == 0;
    }

    void TestPowerOfTwo() {
        if (IsTwoPower(3)) {
            std::cout << "3 is Two Power" << std::endl;
        }
        if (IsTwoPower(4)) {
            std::cout << "4 is Two Power" << std::endl;
        }
        if (IsTwoPower(8)) {
            std::cout << "8 is Two Power" << std::endl;
        }
        if (IsTwoPower(18)) {
            std::cout << "18 is Two Power" << std::endl;
        }
    }

    std::string GetDeleteNRet(std::string inputNum, int deleteK) {
        std::stack<char> numStack;
        int deleteRec = deleteK;
        for(int i = 0; i < inputNum.size(); i++) {
            while (!numStack.empty() && numStack.top() > inputNum[i] && deleteRec > 0) {
                numStack.pop();
                deleteRec--;
            }
            numStack.push(inputNum[i]);
        }

        std::stack<char> outStack;
        while (!numStack.empty()) {
            int num = numStack.top();
            numStack.pop();
            outStack.push(num);
        }
        int restoreLen = static_cast<int>(inputNum.size() - deleteK); // restoreLen <= stackLenSize
        int count = 0;
        std::string retStr;
        bool isStartZero = true;
        while(count < restoreLen) {
            while (isStartZero && outStack.top() == '0') {
                outStack.pop();
                count++;
            }
            isStartZero = false;
            retStr += outStack.top();
            outStack.pop();
            count++;
        }
        return retStr;
    }

    void TestDeleteNGetMin() {
        std::cout << GetDeleteNRet("31241246", 4) << std::endl;
    }


    int GetReverseIdxEnd(int* array, int len) {
        for (int i = len - 1; i > 0; i--) {
            if (array[i] > array[i-1]) {
                return i;
            }
        }
        return 0;
    }

    int GetFirstBiggerNumIdx(int* array, int len, int startIdx) {
        int cmpNum = array[startIdx - 1];
        for (int i = len - 1; i >= startIdx; i--) {
            if (cmpNum < array[i]) {
                return i;
            }
        }
        return startIdx;
    }

    void Reverse(int* array, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp; 
        }
    }

    void GetNextPermutation(int* array, int len) {
        int idx_start = GetReverseIdxEnd(array, len);
        if (idx_start == 0) {
            Reverse(array, 0, len - 1);
        }
        int idx_swap = GetFirstBiggerNumIdx(array, len, idx_start);
        
        // swap num
        int tmp = array[idx_start - 1];
        array[idx_start - 1] = array[idx_swap];
        array[idx_swap] = tmp;

        // reverse segment
        Reverse(array, idx_start, len - 1);
    }

    void TestNextPermutation() {
        std::vector<int> array = {1, 2, 3, 5, 4};
        GetNextPermutation(array.data(), static_cast<int>(array.size()));
        for(auto& item : array) {
            std::cout << "val: " << item << " , ";
        }
        std::cout << std::endl;
    }
}