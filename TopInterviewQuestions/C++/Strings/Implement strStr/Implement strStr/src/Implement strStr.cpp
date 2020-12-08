//Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
//For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
#include <iostream>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int hCount = 0, nCount = 0; //Counters for haystack and needle
        int nTemp = -1, index = -1; //holder for next possible needle start and final needle index

        if (0 >= needle.length())   // given contraint - empty needle returns 0
            return 0;
        if (haystack.length() < needle.length())    // can't match if hackstack is smaller than needle
            return -1;

        while (hCount < haystack.length() && nCount < needle.length()) {
            // find next possible start for needle
            if (index != -1 && nTemp == -1 && haystack[hCount] == needle[0])
                nTemp = hCount;
            // check current index for next needle letter
            if (haystack[hCount] == needle[nCount]) {
                if (index == -1)
                    index = hCount;
                nCount++;
                hCount++;
            }
            else {  // fail
                if (nTemp != -1) {
                    hCount = nTemp; // start from next possible match
                    nTemp = -1;
                }
                else
                    hCount++;
                if ((haystack.length() - hCount) < needle.length()) // not enough characters in haystack to match
                    return -1;
                // return index to no match
                index = -1;
                nCount = 0;
            }
        }
        return index;
    }
};

int main() {
    Solution solution;

    std::string haystack = "hello";
    std::string needle = "ll";

    int output = solution.strStr(haystack, needle);

    std::cout << output << std::endl;

	std::cin.get();
}