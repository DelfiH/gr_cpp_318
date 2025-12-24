#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>
#include <memory>
#include <utility>

class TreeNode {
private:
    int value;
    TreeNode* root = nullptr;
    std::vector<std::unique_ptr<TreeNode>> children;
public:
    TreeNode(int val): value(val) { }

    TreeNode(const TreeNode&) = delete;
    TreeNode& operator=(const TreeNode&) = delete;

    TreeNode* AddChild(int child_value) {
        std::unique_ptr<TreeNode> node(new TreeNode(child_value));
        node->root = this;
        TreeNode* nodePtr = node.get();
        children.push_back(std::move(node));
        return nodePtr;
    }

    void Print(int depth = 0) const {
        for (int i = 0; i < depth; ++i) {
            std::cout << " ";
        }
        std::cout << "- " << value << "\n";
        for (const auto& child : children) {
            child->Print(depth + 1);
        }
    }
    ~TreeNode() {
        // std::cout << "Deleting node with value: " << value << std::endl;
    }
};

void run_tree_task();

#endif // TREE_H
