#include <iostream>

#define LOG(x) std::cout << x << std::endl;

class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) return 1; // assume always n > 0
        int first = 1; int second = 2;

        for (int i = 3; i <= n; i++) {
            int third = first + second;
            first = second;
            second = third;
        }

        return second;
    }
};

int main() {
    int input = 44;

    Solution s;

    int output = s.climbStairs(input);

    LOG("output: " << output);

    std::cout << std::cin.get();
}