//https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/771/
#include <iostream>

//definition for singly-linked list.
struct ListNode {
    int val;
    ListNode*next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode*next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode* begin = nullptr;
        ListNode* curr = nullptr;
        ListNode** p1 = &l1;
        ListNode** p2 = &l2;

        if (!l1 && !l2) {}
        else if (!l1)
            begin = l2;
        else if (!l2)
            begin = l1;
        else {
            if (l1->val > l2->val) {
                begin = l2;
                curr = begin;
                *p2 = (*p2)->next;
            }
            else {
                begin = l1;
                curr = begin;
                *p1 = (*p1)->next;
            }

            while (p1 && p2 && (*p1)->next && (*p2)->next) {
                //std::cout << "Comp l1: " << (*p1)->val << " vs l2: " << (*p2)->val << std::endl;
                if ((*p1)->val > (*p2)->val) {
                    curr->next = *p2;
                    curr = *p2;
                    *p2 = (*p2)->next;
                    //std::cout << "l2" << std::endl;
                }
                else {
                    curr->next = *p1;
                    curr = *p1;
                    *p1 = (*p1)->next;
                    //std::cout << "l1" << std::endl;
                }
            }

            if ((p1 || (*p1)->next) && (p2 || (*p2)->next)) {
                //std::cout << "Comp l1: " << (*p1)->val << " vs l2: " << (*p2)->val << std::endl;
                /*if (p2)
                    std::cout << "p2 is" << std::endl;
                if ((*p2)->next)
                    std::cout << "p2n is" << std::endl;*/
                if ((*p2)->next && ((*p1)->val > (*p2)->val)) {
                    curr->next = *p2;
                    curr = *p2;
                    *p2 = (*p2)->next;
                    //std::cout << "l2" << std::endl;
                }
                else if ((*p1)->next) {
                    curr->next = *p1;
                    curr = *p1;
                    *p1 = (*p1)->next;
                    //std::cout << "l1" << std::endl;
                }
            }
            if (p1 != nullptr || (*p1)->next != nullptr) {
                curr->next = *p1;
                curr = *p1;
                *p1 = (*p1)->next;
                //std::cout << "Finish l1" << std::endl;
            }
            if (p2 != nullptr || (*p2)->next != nullptr) {
                curr->next = *p2;
                curr = *p2;
                *p2 = (*p2)->next;
                //std::cout << "Finish l2" << std::endl;
            }
        }

        return begin;
    }
};

int main() {
    Solution sol;
    ListNode one;
    ListNode two;

    sol.mergeTwoLists(&one, &two);
}