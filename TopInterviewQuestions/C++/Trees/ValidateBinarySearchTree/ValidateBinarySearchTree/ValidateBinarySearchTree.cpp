// https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/625/

#include <iostream>
#include <stack>
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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        std::stack<TreeNode*> s;
        TreeNode* current = root;
        TreeNode* last = nullptr;
        while (!s.empty() || current) {
            while (current) {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            if (last && last->val >= current->val) return false;
            last = current;
            current = current->right;
        }
        return true;
    }
};

int main() {

}