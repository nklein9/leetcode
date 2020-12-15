#include <iostream>
#include <vector>
#include <algorithm>

#define LOG(x) std::cout << x << std::endl;

class Solution {
public:
    std::vector<int> original;
    std::vector<int> contents;
public:
    Solution(std::vector<int>& nums) {
        this->original = nums;
        this->contents = this->original;
        LOG("original: ");
        if (this->original.empty()) LOG("empty");
        for (int i = 0; i < this->original.size(); i++) {
            LOG(original[i] << " ");
        }
    }

    /** Resets the array to its original configuration and return it. */
    std::vector<int> reset() {
        this->contents = this->original;
        LOG("reset");
        LOG("contents: ");
        for (int i = 0; i < this->contents.size(); i++) {
            LOG("size: " << this->contents.size())
                LOG(contents[i] << " ");
        }
        return this->contents;
    }

    /** Returns a random shuffling of the array. */
    std::vector<int> shuffle() {
        std::random_shuffle(this->contents.begin(), this->contents.end());
        return this->contents;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

int main() {
    std::vector<int> input = { 1, 2, 3 };
    Solution s = Solution(input);
    std::vector<int> shuffle = s.shuffle();
    LOG("shuffle: ");
    for (int i = 0; i < shuffle.size(); i++) {
        LOG(shuffle[i] << " ");
    }
    std::vector<int> reset = s.reset();
    std::vector<int> shuffle2 = s.shuffle();
    LOG("shuffle2: ");
    for (int i = 0; i < shuffle2.size(); i++) {
        LOG(shuffle2[i] << " ");
    }

    std::cout << std::cin.get();
    return 0;
}