#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) { }
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int temp = l1->val + l2->val;
        int carry = 0;
        if (temp / 10 > 0)
            carry = 1;

        ListNode* out = new ListNode;
        out->val = temp % 10;
        ListNode* travel = out;

        if (l1 != nullptr)
            l1 = l1->next;
        if (l2 != nullptr)
            l2 = l2->next;

        while(l1 != nullptr || l2 != nullptr || carry == 1)
        {
            // 4 possibilities of what temp can be
            if (l1 == nullptr && l2 != nullptr)
                temp = l2->val + carry;
            else if (l2 == nullptr && l1 != nullptr)
                temp = l1->val + carry;
            else if (l1 == nullptr && l2 == nullptr)
                temp = carry;
            else
                temp = l1->val + l2->val + carry;

            // carry section
            carry = 0;
            if (temp / 10 > 0)
                carry = 1;

            //creation of new node, moving travel into new node
            ListNode* newNode = new ListNode;
            newNode->val = temp % 10;
            newNode->next = nullptr;
            travel->next = newNode;
            travel = travel->next;

            //movement of l1 and l2
            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }
        return out;
    }

};

void print(ListNode* num)
{
    ListNode* temp = num;
    while (temp != nullptr)
    {
        std::cout << temp->val;
        temp = temp->next;
    }
        
}
