#include <iostream>

class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0;
        int sign = 1;
        int result = 0;

        // remove front spaces
        while (i < s.length() && s[i] == ' ')
            i++;

        // check for sign or front letters
        if (!isdigit(s[i]) && s[i] == '-' || s[i] == '+') {
            sign = (sign == 1) && (s[i] == '-') ? -1 : 1;
            i++;
        }

        // find result within bounds
        while (i < s.length()) {
            //non-digit - return with current result
            if (!isdigit(s[i]))
                return result * sign;

            // add digit
            if (INT_MAX / 10 >= result)
                result *= 10;
            else
                return sign == 1 ? INT_MAX : INT_MIN;
            if ((INT_MAX - (s[i] - '0')) >= result)
                result += (s[i] - '0');
            // overflow
            else
                return sign == 1 ? INT_MAX : INT_MIN;

            i++;
        }
        return result * sign;
    }
};

int main() {
    std::string input = "42";
    Solution solution;

    int result= solution.myAtoi(input);

    std::cout << result << std::endl;

	std::cin.get();
}