#include <iostream>
#include <vector>

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        char temp;
        int a = s.size();

        for (int i = 0; i <= a/2 - 1; i++) {
            temp = s[a - i - 1];
            s[s.size() - i - 1] = s[i];
            s[i] = temp;
        }

        for (int i = 0; i < s.size(); i++) {
            std::cout << s[i];
        }
        std::cout << std::endl;
    }
};

int main() {
    std::vector<char> s = { 'h', 'e', 'l', 'l', 'o' };
    for (int i = 0; i < s.size(); i++) {
        std::cout << s[i];
    }
    std::cout << std::endl;
    Solution solution;
    solution.reverseString(s);
    std::cin.get();

    return 0;
}