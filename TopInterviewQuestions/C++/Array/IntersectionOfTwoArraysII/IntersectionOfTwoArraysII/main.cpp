//Given two arrays, write a function to compute their intersection.

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> nums1 = { 1, 2, 2, 1 };
std::vector<int> nums2 = { 2, 2 };

int main() {
	std::vector<int> out;
	sort(nums1.begin(), nums1.end());

	for (int x = 0; x < sizeof(nums2); x++) {
		if (std::find(nums1.begin(), nums1.end(), nums2[x]) != nums1.end()) {
			out.emplace_back(nums2[x]);
		}
	}

	std::cout << "out" << std::endl;
	for (int x = 0; x < sizeof(out); x++) {
		std::cout << out[x] << std::endl;
	}


	std::cin.get();

	return 0;
}

/*
std::unordered_map<const int, int> intersection;
	if (sizeof(nums1) > sizeof(nums2)) {
		int output[sizeof(nums2)];
	}
	else {

	}
	int output[sizeof(nums1)];

	for (int i = 0; i + 1 < sizeof(nums1); i++) {
			intersection.insert(nums1[i], i);
	}
	for (int j = 0; j + 1 < sizeof(nums2); j++) {
		if (intersection.find(nums2[j]) != intersection.end()) {
			intersection.erase(nums2[j]);
			output.append(nums2[j]);
		}
	}

	for (auto& x : intersection) {
		std::cout << x.first << ": " << x.second << std::endl;
	}
	for (auto& y : output) {
		std::cout << output[y] << std::endl;
	}
*/