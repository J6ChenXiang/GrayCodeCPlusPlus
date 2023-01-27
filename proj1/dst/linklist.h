#pragma once

namespace dst {
    typedef struct Node {
        int data_ {0};
        Node* next_ {nullptr};
        Node(int data) : data_(data) {}
    } Node;

    class LinkList {
    private:
        Node* head {nullptr};
        Node* last {nullptr};
        int size {0};
    public:
        bool InsertNode(int data, int index);
        bool DeleteNode(int index);
        int GetNodeVal(int index);
        bool UpdateNodeVal(int index, int data);
        void Output();
        void Push_Front(int data);
        void Push_Back(int data);
        int Size();
        LinkList() = default;
        ~LinkList();
    private:
        Node* GetNodeByIndex(int index);
    };

    void TestLinkListPushBackFrontAndGet();
    void TestLinkListInsertAndDelete();
}