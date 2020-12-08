//https://leetcode.com/problems/palindrome-number/

#include <iostream>
#include <vector>

class Solution {
public:
    bool isPalindrome(int x) {
        std::vector<int> numList;
        if (x < 0 || ((x % 10 == 0) && x != 0)) {
            return false;
        }
        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }
        return x == revertedNumber || x == revertedNumber / 10;
    }
};

int main() {
    Solution solutionObj;
    int input = 1221;    //ex 121, -121, 10

    if (solutionObj.isPalindrome(input)) {
        std::cout << input << " is a palindrome!" << std::endl;
    }
    else {
        std::cout << input << " is not a palindrome!" << std::endl;
    }

    std::cin.get();
}