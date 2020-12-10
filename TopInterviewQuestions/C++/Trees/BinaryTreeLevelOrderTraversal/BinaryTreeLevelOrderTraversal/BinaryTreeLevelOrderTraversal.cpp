#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> output;  std::vector<int> level;
        if (root == nullptr) return output;
        std::queue<TreeNode*> q;
        int nodeTotal = 0;

        TreeNode* current = root;
        level.push_back(current->val);
        output.push_back(level); level.clear();

        if (current->left) { q.push(current->left); nodeTotal++; }
        if (current->right) { q.push(current->right); nodeTotal++; }

        while (!q.empty()) {
            int c = nodeTotal; nodeTotal = 0;
            std::cout << "nodeTotal: " << nodeTotal << std::endl;
            for (int i = 0; i < c && !q.empty(); i++) {
                std::cout << "q size: " << q.size() << std::endl;
                std::cout << "node: " << i << std::endl;
                current = q.front();
                level.push_back(current->val);
                if (current->left) { q.push(current->left); nodeTotal++; }
                if (current->right) { q.push(current->right); nodeTotal++; }
                q.pop();
            }
            std::cout << "end Level" << std::endl;
            output.push_back(level); level.clear();
        }
        return output;
    }
};

int main() {

}
