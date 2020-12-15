#include <iostream>
#include <vector>
#include <climits>

#define LOG(x) std::cout << x << std::endl;

class MinStack {
public:
    std::vector<int> v;
public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x) {
        this->v.push_back(x);
        LOG("pushed: " << this->v.back());
    }

    void pop() {
        LOG("poping: " << this->v.back());
        this->v.pop_back();
        if (!this->v.empty()) LOG("back: " << this->v.back());
    }

    int top() {
        LOG("top: " << this->v.back());
        return this->v.back();
    }

    int getMin() {
        int min = INT_MAX;
        for (int i = 0; i < this->v.size(); i++) {
            if (this->v[i] < min) min = this->v[i];
        }
        LOG("min: " << min);
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    MinStack m;
    m.push(1); m.push(2); m.pop(); m.push(3); m.getMin();


    std::cout << std::cin.get();
}