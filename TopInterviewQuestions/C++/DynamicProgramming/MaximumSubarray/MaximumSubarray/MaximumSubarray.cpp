//1 <= nums.length <= 2 * 104
//-2^31 <= nums[i] <= 2^31 - 1

#include <iostream>
#include <vector>

int max(int a, int b) { return (a > b) ? a : b; }

// A utility funtion to find maximum of three integers 
int max(int a, int b, int c) { return max(max(a, b), c); }

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {	//O(n) approach
		int max = INT_MIN; int curr = 0;
		for (int i = 0; i < nums.size(); i++) {
			curr = curr + nums[i];
			if (curr > max) max = curr; 
			if (curr < 0) curr = 0;
		}
		return max;
    }/*
	int maxSubArray(std::vector<int>& nums) {	//Div and Conquer approach [BROKEN]
		std::cout << "msa" << std::endl;
		for (int i = 0; i < nums.size(); i++)
			std::cout << nums[i] << ", ";
		std::cout << std::endl;
		if (nums.size() == 1) {
			std::cout << "end: " << nums[0] << std::endl;  return nums[0];
		}
		int leftSub = INT_MIN;  int rightSub = INT_MIN; int curr = 0;
		int mid = (nums.size() / 2) - 1;
		for (int i = 0; i <= mid; i++) {
			std::cout << "ls: " << i << ", ";
			curr = curr + nums[i];
			if (curr > leftSub) leftSub = curr;
			if (curr < 0) curr = 0;
		}
		std::cout << std::endl;
		curr = 0;
		for (int i = mid + 1; i < nums.size(); i++) {
			std::cout << "rs: " << i << ", ";
			curr = curr + nums[i];
			if (curr > rightSub) rightSub = curr;
			if (curr < 0) curr = 0;
		}
		std::cout << std::endl;
		std::cout << "/msa" << std::endl;

		std::cout << "l" << std::endl;
		std::vector<int> left(nums.begin(), nums.begin() + mid); 
		int a = maxSubArray(left);
		std::cout << "r" << std::endl;
		std::vector<int> right(nums.begin() + mid + 1, nums.end());
		int b = maxSubArray(right);

		return max(a, b, max(leftSub + rightSub, leftSub, rightSub));
	}*/
};

int main() {
	std::vector<int> input = { -2,1,-3,4,-1,2,1,-5,4 };

	Solution s;

	int output = s.maxSubArray(input);

	std::cout << "Output: " << output << std::endl;

	std::cout << std::cin.get();
	return 0;
}