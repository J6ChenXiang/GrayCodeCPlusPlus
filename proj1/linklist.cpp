#include <iostream>
#include "dst/linklist.h"

namespace dst {
    void TestLinkListInsertAndDelete() {
        dst::LinkList mylist;
        for(int i = 0; i < 4; i++) {
            mylist.Push_Back(i);
        }
        std::cout << "after init: " << std::endl;
        mylist.Output();
        mylist.InsertNode(4, 0);
        std::cout << "after insert at 0: " << std::endl;
        mylist.Output();
        std::cout << "after insert at 4: " << std::endl;
        mylist.InsertNode(5, 4);
        mylist.Output();
        std::cout << "size: " << mylist.Size() << std::endl;
        
        mylist.DeleteNode(0);
        std::cout << "after delete at 0: " << std::endl;
        mylist.Output();
        mylist.DeleteNode(4);
        std::cout << "after delete at 4: " << std::endl;
        mylist.Output();

        mylist.DeleteNode(2);
        std::cout << "after delete at 2: " << std::endl;
        mylist.Output();
    }

    void TestLinkListPushBackFrontAndGet() {
        dst::LinkList mylist;    
        mylist.Push_Back(1);
        std::cout << "after push back: " << std::endl;
        mylist.Output();

        mylist.Push_Front(2);
        std::cout << "after push front: " << std::endl;
        mylist.Output();

        mylist.Push_Back(3);
        std::cout << "after push back again: " << std::endl;
        mylist.Output();

        mylist.Push_Front(4);
        std::cout << "after push front again: " << std::endl;
        mylist.Output();

        for(int i = 0; i < mylist.Size(); i++) {
            std::cout << "Get node: " << i << " Val: " 
                << mylist.GetNodeVal(i) << std::endl;
        }
    }

    bool LinkList::InsertNode(int data, int index) {
        if (index >= size) {
            return false;
        } // out of bounds
        Node* toInsertNode = new Node(data);
        if (size == 0) {
            head = toInsertNode;
            last = toInsertNode; // list is null, init
        } else if ((size - 1) == index) {
            last->next_ = toInsertNode;
            last = toInsertNode; // insert in the end
        } else {
            Node* tmp = GetNodeByIndex(index);
            toInsertNode->next_ = tmp->next_;
            tmp->next_ = toInsertNode; // insert in the middle, insert node next
        }
        size++;
        return true;
    }

    bool LinkList::DeleteNode(int index) {
        if (index >= size) {
            return false;
        }
        Node* toDeleteNode = nullptr;
        int count = 0;
        Node* prev = nullptr;
        Node* tmp = head;
        while (tmp != nullptr && count < index) {
            prev = tmp;
            tmp = tmp->next_;
            count++;
        }
        if (size == 1 && index == 0) {
            toDeleteNode = head;
            head = nullptr;
            last = nullptr; // linklist delete to null, init
        } else if (index == 0) {
            toDeleteNode = head;
            head = head->next_; // delete head node
        } else if (index == (size - 1)) {
            toDeleteNode = last;
            last = prev;
            prev->next_ = nullptr; // delete last node
        } else {
            toDeleteNode = tmp;
            prev->next_ = tmp->next_; // delete middle node
        }
        delete toDeleteNode;
        size--;
        return true;
    }

    int LinkList::GetNodeVal(int index) {
        Node* tmp = GetNodeByIndex(index);
        if (tmp == nullptr) {
            std::cout << "index out of bounds" << std::endl;
            return 0;
        } 
        return tmp->data_;
    }

    bool LinkList::UpdateNodeVal(int index, int data) {
        Node* tmp = GetNodeByIndex(index);
        if (tmp == nullptr) {
            std::cout << "index out of bounds" << std::endl;
            return false;
        }
        tmp->data_ = data;
        return true;
    }

    Node* LinkList::GetNodeByIndex(int index) {
        int count = 0;
        Node* tmp = head;
        while (tmp != nullptr && count < index) {
            tmp = tmp->next_;
            count++;
        }
        return tmp;
    }

    LinkList::~LinkList() {
        while (head != last) {
            Node* tmp = head;
            head = head->next_;
            delete tmp;
        }
        head = nullptr;
        last = nullptr;
    }

    void LinkList::Output() {
        Node* tmp = head;
        while (tmp != nullptr) {
            std::cout << "data: " << tmp->data_ << std::endl;
            tmp = tmp->next_;
        }
    }

    void LinkList::Push_Front(int data) {
        Node* insertNode = new Node(data);
        if (size == 0) {
            head = insertNode;
            last = insertNode;
        } else {
            insertNode->next_ = head;
            head = insertNode;
        }
        size++;
    }

    void LinkList::Push_Back(int data) {
        Node* insertNode = new Node(data);
        if (size == 0) {
            head = insertNode;
            last = insertNode;
        } else {
            last->next_ = insertNode;
            last = insertNode;
        }
        size++;
    }

    int LinkList::Size() {
        return size;
    }
}
