#include <iostream>
#include <vector>
#include <string>

#define LOG(x) std::cout << x << std::endl;

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
    TreeNode* sortedArrayToBST(std::vector<int>& nums, int begin, int end) {
        LOG("BST1");
        if (begin > end) return nullptr;
        LOG("not null");

        std::cout << "input vector: ";
        for (int i = 0; i < nums.size(); i++)
            std::cout << nums[i] << " ";
        std::cout << " Begin: " << begin << " End: "  << end << std::endl;

        int mid = (begin + end) / 2;
        LOG("Val: " << nums[mid])
        TreeNode* root = newNode(nums[mid]);

        LOG("start left");
        root->left = sortedArrayToBST(nums, begin, mid - 1);
        if (root->left != nullptr) LOG("Left: " << root->left->val);
        root->right = sortedArrayToBST(nums, mid + 1, end);
        LOG("start right");
        if (root->left != nullptr) LOG("Right: " << root->right->val);

        return root;
    }
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        int begin = 0; int end = nums.size() - 1;
        LOG("BST2");
        if (nums.empty()) return nullptr;
        if (0 > nums.size()-1) return nullptr;

        std::cout << "input vector: ";
        for (int i = 0; i < nums.size(); i++)
            std::cout << nums[i] << " ";
        std::cout << " Begin: " << begin << " End: " << end << std::endl;

        int mid = (nums.size() - 1) / 2;
        LOG("Val: " << nums[mid])
        TreeNode* root = newNode(nums[mid]);

        LOG("start left");
        root->left = sortedArrayToBST(nums, begin, mid - 1);
        LOG("Left: " << root->left->val);
        LOG("start right");
        root->right = sortedArrayToBST(nums, mid + 1, end);
        LOG("Right: " << root->right->val);

        return root;
    }
    TreeNode* newNode(int data) {
        TreeNode* node = new TreeNode;
        node->val = data;
        node->left = NULL;
        node->right = NULL;

        return node;
    }
    void printTree(TreeNode* node) {
        if (node == NULL) {
            return;
        }
        std::cout << node->val << " ";
        printTree(node->left);
        printTree(node->right);
    }
};

int main() {
    int inInt[] = { -10,-3,0,5,9 };
    std::vector<int> input = { inInt, inInt + (sizeof(inInt) / sizeof(int)) };
    LOG(1);
    Solution sol;
    LOG(2);
    TreeNode* out = sol.sortedArrayToBST(input);
    LOG(3);
    sol.printTree(out);
    std::cout << std::cin.get();
}

