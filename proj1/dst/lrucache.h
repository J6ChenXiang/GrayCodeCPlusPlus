#pragma once

#include <map>
#include <string>

namespace dst {
    typedef struct LruNode {
        std::string key_;
        std::string val_;        
        LruNode* next_ {nullptr};
        LruNode* pre_ {nullptr};
        LruNode(std::string key, std::string val)
            : key_(key), val_(val) {}
    } LruNode;

    class LruCache {
    private:
        int limit_ {0};
        std::map<std::string, LruNode*> lruMap;
        LruNode* head {nullptr};
        LruNode* end {nullptr};
    public:
        void PushVal(std::string key, std::string val);
        std::string GetVal(std::string key);
        void RemoveVal(std::string key);
        std::string GetLatestVal();
        std::string GetOldestVal();
        LruCache(int limit):limit_(limit) {}
        ~LruCache();
    private:
        LruNode* RemoveNode(LruNode* node);
        void AddNode(LruNode* node);
        void RefreshNode(LruNode* node);
    };

    void TestLruCache();
}