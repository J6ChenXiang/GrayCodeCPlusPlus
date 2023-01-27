#include "dst/bitree.h"
#include <queue>
#include <iostream>
#include <stack>
#include "dst/bitree.h"

namespace dst {
    void BiTree::CreateFromArray(int* array, int len) {
        std::queue<TreeNode*> nodeQ;
        root = new TreeNode(array[0]);
        nodeQ.push(root);
        int idx = 1;
        while (idx < len) {
            TreeNode* nowNode = nodeQ.front();
            nodeQ.pop();
            if (idx < len) {
                TreeNode* leftNode = new TreeNode(array[idx]);
                nowNode->left = leftNode;
                nodeQ.push(leftNode);
            }
            idx++;
            if (idx < len) {
                TreeNode* rightNode = new TreeNode(array[idx]);
                nowNode->right = rightNode;
                nodeQ.push(rightNode);
            }
            idx++;
        }
    }

    void BiTree::TraverseDfs_Beg(TreeNode* node) {
        if (node == nullptr) {
            return ;
        }
        std::cout << "nodeVal: " << node->data_ << " , ";
        TraverseDfs_Beg(node->left);
        TraverseDfs_Beg(node->right);
    }

    void BiTree::TraverseDfs_Mid(TreeNode* node) {
        if (node == nullptr) {
            return ;
        }
        TraverseDfs_Mid(node->left);
        std::cout << "nodeVal: " << node->data_ << " , ";
        TraverseDfs_Mid(node->right);
    }

    void BiTree::TraverseDfs_End(TreeNode* node) {
        if (node == nullptr) {
            return ;
        }
        TraverseDfs_End(node->left);
        TraverseDfs_End(node->right);
        std::cout << "nodeVal: " << node->data_ << " , ";
    }

    void BiTree::TraverseDfs_Beg() {
        TraverseDfs_Beg(root);
        std::cout << std::endl;
    }

    void BiTree::TraverseDfs_Mid() {
        TraverseDfs_Mid(root);
        std::cout << std::endl;
    }

    void BiTree::TraverseDfs_End() {
        TraverseDfs_End(root);
        std::cout << std::endl;
    }

    void BiTree::TraverseBfs() {
         std::queue<TreeNode*> nodeQ;
         nodeQ.push(root);
         while (!nodeQ.empty()) {
            size_t levelNodeSize = nodeQ.size();
            for (size_t i = 0; i < levelNodeSize; i++) {
                TreeNode* node = nodeQ.front();
                nodeQ.pop();
                std::cout << "nodeVal: " << node->data_ << " , ";
                if (node->left != nullptr) {
                    nodeQ.push(node->left);
                }
                if (node->right != nullptr) {
                    nodeQ.push(node->right);
                }
            }
         }
         std::cout << std::endl;
    }

    void BiTree::TraverseStack() {
        std::stack<TreeNode*> nodeS;
        TreeNode* node = root;
        while (node != nullptr || !nodeS.empty()) {
            while (node != nullptr) {
                nodeS.push(node);
                std::cout << "nodeVal: " << node->data_ << " , ";
                node = node->left;
            }
            if (!nodeS.empty()) {
                node = nodeS.top();
                nodeS.pop();
                node = node->right;
            }
        }
        std::cout << std::endl;
    }

    BiTree::~BiTree() {
        std::cout << "destroy treeNode" << std::endl;
        TraverseDestroy(root);
    }

    void BiTree::TraverseDestroy(TreeNode* node) {
        if (node == nullptr) {
            return ;
        }
        TraverseDestroy(node->left);
        TraverseDestroy(node->right);
        // std::cout << "destroy node: " << node->data_ << std::endl;
        delete node;
        node = nullptr;
    }

    void TestBiTree() {
        BiTree tree;
        int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        tree.CreateFromArray(arr, 10);
        tree.TraverseDfs_Beg();
        tree.TraverseDfs_Mid();
        tree.TraverseDfs_End();
        tree.TraverseBfs();
        tree.TraverseStack();
    }
}









