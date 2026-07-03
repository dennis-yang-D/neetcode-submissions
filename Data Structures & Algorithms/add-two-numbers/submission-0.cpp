/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = new ListNode();
        ListNode* curr = sum;
        
        int carry = 0;
        while(l1 && l2) {
            int v = l1->val + l2->val + carry;
            if(v > 9) {carry = 1;}
            else {carry = 0;}
            ListNode* next = new ListNode(v % 10);
            curr->next = next;
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            int v = l1->val + carry;
            if(v > 9) {carry = 1;}
            else {carry = 0;}
            ListNode* next = new ListNode(v % 10);
            curr->next = next;
            curr = curr->next;
            l1 = l1->next;
        }
        while(l2) {
            int v = l2->val + carry;
            if(v > 9) {carry = 1;}
            else {carry = 0;}
            ListNode* next = new ListNode(v % 10);
            curr->next = next;
            curr = curr->next;
            l2 = l2->next;
        }
        if(carry > 0) {
            ListNode* next = new ListNode(carry);
            curr->next = next;
            curr = curr->next;
        }

        return sum->next;
    }
};
