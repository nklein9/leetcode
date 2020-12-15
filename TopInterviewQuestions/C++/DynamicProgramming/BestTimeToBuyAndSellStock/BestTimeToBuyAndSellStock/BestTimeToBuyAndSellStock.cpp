#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.empty()) return 0;
        int profit = 0; int buy = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] - buy > profit)
                profit = prices[i] - buy;
            else if (prices[i] < buy)
                buy = prices[i];
        }
        return profit;
    }
};

int main() {
    std::vector<int> input = { 7,6,4,3,1 };

    Solution s;
    int output = s.maxProfit(input);

    std::cout << "output: " << output << std::endl;

    std::cout << std::cin.get();
}