// https://leetcode.com/problems/reverse-integer/
#include <iostream>
#include <cmath>

class Solution {
public:
    int reverse(int x) {
        int output = 0;
        std::cout << "output: " << output << std::endl;
        while (x != 0)
        {
            int rem = x % 10;
            std::cout << "rem: " << rem << std::endl;
            x /= 10;
            std::cout << "x: " << x << std::endl;
            if ((output > INT_MAX / 10) || ((output == INT_MAX / 10) && rem > 7)) return 0;
            if ((output < INT_MIN / 10) || ((output == INT_MIN / 10) && rem < -8)) return 0;
            output = output * 10 + rem;
            std::cout << "output: " << output << std::endl;
        }
        return output;
    }
};

int main() {
    int input = -1234;
    std::cout << input << std::endl << std::endl;

    Solution solutionObj;

    int result = solutionObj.reverse(input);
    std::cout << result << std::endl;

    std::cin.get();
}