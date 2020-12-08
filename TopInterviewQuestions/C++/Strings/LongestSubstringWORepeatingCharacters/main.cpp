//https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
	int lengthOfLongestSubstring(std::string s) {
		int longest = 0;
		std::vector<char> subString;
		std::vector<char>::iterator it;

		for (int i = 0; i < (int)s.size(); i++) {
			it = std::find(subString.begin(), subString.end(), s[i]);	//search current character
			if (it != subString.end()) {								//if you find it
				subString.erase(subString.begin(), it + 1);				//erase up to and including that character
			}
			subString.push_back(s[i]);
			if (longest < subString.size()) {
				longest = subString.size();
			}
		}
		return longest;
	}
};

int main() {
	Solution solutionObj;
	std::string input = "abcabcbb";
	std::cout << "input: " << input << std::endl;

	int length = solutionObj.lengthOfLongestSubstring(input);

	std::cout << "Longest Substring length with no repeat char: " << length << std::endl;
	
	std::cin.get();
}