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

int main()
{
    Solution mySol;

    ListNode* numA1 = new ListNode;
    ListNode* numA2 = new ListNode;
    ListNode* numA3 = new ListNode;
    ListNode* numA4 = new ListNode;
    ListNode* numA5 = new ListNode;
    ListNode* numA6 = new ListNode;
    numA1->val = 2;
    numA1->next = numA2;
    numA2->val = 4;
    numA2->next = numA3;
    numA3->val = 3;
    numA3->next = numA4;
    numA4->val = 9;
    numA4->next = numA5;
    numA5->val = 9;
    numA5->next = numA6;
    numA6->val = 9;


    ListNode* numB1 = new ListNode;
    ListNode* numB2 = new ListNode;
    ListNode* numB3 = new ListNode;
    ListNode* numB4 = new ListNode;
    numB1->val = 5;
    numB1->next = numB2;
    numB2->val = 6;
    numB2->next = numB3;
    numB3->val = 4;
    numB3->next = numB4;
    numB4->val = 9;

    ListNode* myListSol = mySol.addTwoNumbers(numA1, numB1);

    print(myListSol);
    

    return 0;
}

