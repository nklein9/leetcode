// Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.
//Examples:
//s = "leetcode"
//return 0.
//
//s = "loveleetcode"
//return 2.
//Note: You may assume the string contains only lowercase English letters.

#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    int firstUniqChar(std::string s) {
        int count[26] = {};

        for (int i = 0; i < s.length(); i++) {
            int index = s.at(i) - 'a';
            count[index]++;
        }
        for (int i = 0; i < s.length(); i++) {
            int index = s.at(i) - 'a';
            if (count[index] == 1) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    std::string input = "leetcode";
    Solution solution;
    int output = solution.firstUniqChar(input);
    std::cout << "First Unique Char: " << output << std::endl;
    std::cin.get();
}