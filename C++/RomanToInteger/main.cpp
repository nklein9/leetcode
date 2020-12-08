https://leetcode.com/problems/roman-to-integer/
#include <iostream>
#include <string>

class Solution {
public:
    int romanToInt(std::string s) {
        char* p = &s.front();

    }
};

int main() {
    Solution solutionObj;
    std::string input = "X";

    int converted = solutionObj.romanToInt(input);

    std::cout << input << " converted to arabic characters is " << converted << "!" << std::endl;

    std::cin.get();
}