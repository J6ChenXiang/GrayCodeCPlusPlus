#pragma once

namespace dst {
    typedef struct TreeNode {
        int data_;
        TreeNode* left {nullptr};
        TreeNode* right {nullptr};
        TreeNode(int data):data_(data) {}
    } TreeNode;

    class BiTree {
        TreeNode* root {nullptr};
    public:
        BiTree() = default;
        void CreateFromArray(int* array, int len);
    private:
        void TraverseDfs_Beg(TreeNode* node);
        void TraverseDfs_Mid(TreeNode* node);
        void TraverseDfs_End(TreeNode* node);
    public:
        void TraverseBfs();
        void TraverseStack();
        void TraverseDfs_Beg();
        void TraverseDfs_Mid();
        void TraverseDfs_End();
        ~BiTree();
    private:
        void TraverseDestroy(TreeNode* node);
    };

    void TestBiTree();
}