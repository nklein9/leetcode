// https://leetcode.com/problems/add-two-numbers/

#include <iostream>
#include <vector>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    ~ListNode() {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        ListNode* l3 = NULL;
        ListNode** node = &l3;
        while (l1 != NULL || l2 != NULL || sum > 0)
        {
            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            (*node) = new ListNode(sum % 10);
            sum /= 10;
            node = &((*node)->next);
        }
        return l3;
    }
};

ListNode* arrayMaker(int num) {
    std::cout << "arrayMaker" << std::endl;
    int newNum = num % 10;
    int carryOver = num / 10;
    if (carryOver <= 0) {
        ListNode* newNode = new ListNode(newNum);
        return newNode;
    }
    else {
        ListNode* newNext = arrayMaker(carryOver);
        ListNode* newNode = new ListNode(newNum, newNext);
        return newNode;
    }
}

void arrayDestroyer(ListNode* node) {
    if (node->next != nullptr) {
        arrayDestroyer(node->next);
    }
    delete node;
}

void printLinkedList(ListNode* node) {
    if (node->next != nullptr) {
        printLinkedList(node->next);
    }
    std::cout << node->val << std::endl;
}



int main() {
    Solution solutionObj;
    int num1 = 81; //342 default
    int num2 = 0; //465 default

    std::cout << "array 1" << std::endl;
    ListNode* head1 = arrayMaker(num1);
    printLinkedList(head1);
    std::cout << "array 2" << std::endl;
    ListNode* head2 = arrayMaker(num2);
    printLinkedList(head2);

    std::cout << "array result" << std::endl;
    ListNode* headResult = solutionObj.addTwoNumbers(head1, head2);
    printLinkedList(headResult);

    arrayDestroyer(head1);
    arrayDestroyer(head2);
    arrayDestroyer(headResult);

    std::cin.get();
}