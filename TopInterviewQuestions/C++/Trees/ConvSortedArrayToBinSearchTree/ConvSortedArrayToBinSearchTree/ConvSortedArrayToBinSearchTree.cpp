#include <iostream>
#include <vector>
#include <string>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#define LOG( name, value) std::cout << name << ": " << value << std::endl;
class Solution {
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        if (nums.size() == 0) { TreeNode root; TreeNode* output = &root; return output; }
        
        int center = nums.size() / 2;
        TreeNode root(nums[center]);
        nums.erase(nums.begin()+(center-1));
        TreeNode* current = &root;
        int nodes = nums.size()+1;

        LOG("size", nodes);

        for (int i = 0; i < nodes; i++) {
            LOG("node", i); LOG("CurrentStart", current->val);
            TreeNode next (nums.front());
            while(1) {
                if (nums.empty()) break;
                if (next.val < current->val) {
                    if (current->left) current = current->left;
                    else { current->left = &next; continue; }
                    LOG("CurrentLeft", current->val);
                }
                else if (next.val > current->val) {
                    if (current->right) current = current->right;
                    else { current->right = &next; continue; }
                    LOG("CurrentRight", current->val);
                }
            }
            nums.erase(nums.begin());
        }
        return &root;
    }
};

int main() {

}