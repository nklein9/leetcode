// https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/555/
#include <iostream>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int mDepth = 0;
        int depth;
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        if (root->left != nullptr) {
            depth = 1 + maxDepth(root->left);
            if (depth > mDepth)
                mDepth = depth;
        }
        if (root->right != nullptr) {
            depth = 1 + maxDepth(root->right);
            if (depth > mDepth)
                mDepth = depth;
        }
        return mDepth;
    }
};

int main() {

}