#include "dst/lrucache.h"
#include <iostream>

namespace dst {
    LruNode* LruCache::RemoveNode(LruNode* node) {
        LruNode* toDelete = node;
        if (node == head && node == end) {
            head = nullptr;
            end = nullptr;
        } else if (node == head) {
            head = head->next_;
            head->pre_ = nullptr;
        } else if (node == end) {
            end = end->pre_;
            end->next_ = nullptr;
        } else {
            node->pre_->next_ = node->next_;
            node->next_->pre_ = node->pre_;
        }
        return toDelete;
    }

    void LruCache::AddNode(LruNode* node) {
        if (end != nullptr) {
            node->pre_ = end;
            node->next_ = nullptr;
            end->next_ = node;
        }
        end = node;
        if (head == nullptr) {
            head = node;
        }
    }

    void LruCache::RefreshNode(LruNode* node) {
        if (node == end) {
            return ;
        }
        LruNode* oldNode = RemoveNode(node);
        AddNode(oldNode);
    }

    void LruCache::PushVal(std::string key, std::string val) {
        if (lruMap.count(key) == 0) { // new Node add
            if (lruMap.size() >= limit_) {
                LruNode* toDeleteOld = RemoveNode(head);
                std::string oldKey = toDeleteOld->key_;
                lruMap.erase(oldKey);
                delete toDeleteOld;
                toDeleteOld = nullptr;
            }
            LruNode* newNode = new LruNode(key, val);
            lruMap[key] = newNode;
            AddNode(newNode);
        } else { // update exists
            lruMap[key]->val_ = val;
            RefreshNode(lruMap[key]);
        }
    }

    std::string LruCache::GetVal(std::string key) {
        std::string ans = lruMap[key]->val_;
        RefreshNode(lruMap[key]);
        return ans;
    }

    void LruCache::RemoveVal(std::string key) {
        LruNode* toRemove = lruMap[key];
        LruNode* toDelete = RemoveNode(toRemove);
        delete toDelete;
        toDelete = nullptr;
        lruMap.erase(key);
    }

    std::string LruCache::GetLatestVal() {
        if (end == nullptr) {
            return nullptr; 
        }
        return end->val_;
    }

    std::string LruCache::GetOldestVal() {
        if (head == nullptr) {
            return nullptr;
        }
        return head->val_;
    }

    LruCache::~LruCache() {
        while (head != nullptr) {
            LruNode* toDelete = head;
            head = head->next_;
            delete toDelete;
            toDelete = nullptr;
        }
    }

    void TestLruCache() {
        LruCache cache(5);
        cache.PushVal("one", "1");
        cache.PushVal("two", "2");
        cache.PushVal("three", "3");
        std::cout << "latest after push: " << cache.GetLatestVal() << std::endl;
        std::cout << "get Val: " << cache.GetVal("two") << std::endl;
        std::cout << "latest after get val: " << cache.GetLatestVal() << std::endl;
        cache.RemoveVal("two");
        std::cout << "latest after remove val: " << cache.GetLatestVal() << std::endl;
        cache.PushVal("four", "4");
        cache.PushVal("five", "5");
        cache.PushVal("six", "6");
        std::cout << "latest after push val: " << cache.GetLatestVal() << std::endl;
        std::cout << "oldest after push val: " << cache.GetOldestVal() << std::endl;
        cache.PushVal("seven", "7");
        std::cout << "oldest after push val: " << cache.GetOldestVal() << std::endl;
    }
}