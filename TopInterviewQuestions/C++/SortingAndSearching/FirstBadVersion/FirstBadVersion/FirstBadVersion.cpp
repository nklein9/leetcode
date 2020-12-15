#include <iostream>

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

#define LOG(x) std::cout << x << std::endl;

class Solution {
private:
    int bad = 0;
public:
    int firstBadVersion(int n) {
        int left = 0; int right = INT_MAX;
        int mid;
        while (left < right) {
            mid = (right - left) / 2;
            LOG("Mid: " << mid);
            if (isBadVersion(left + mid)) right = left + mid - 1;
            else left = left + mid + 1;
            LOG("Left: " << left << " Right: " << right);
        }

        if (left < 1) return 1;
        else return left;
    }
    bool isBadVersion(int n) {
        if (n == bad) return true;
        else return false;
    }
    void setBad(int n) {
        this->bad = n;
    }
};

int main() {
    Solution s;

}