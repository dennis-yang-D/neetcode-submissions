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
    void reorderList(ListNode* head) {
        // first, get to halfway in the list
        ListNode* slow_prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow_prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast) {
            slow_prev = slow;
            slow = slow->next;
        }

        slow_prev->next = nullptr;

        // Reverse the list in the second half of the list
        ListNode* rev_prev = nullptr;
        ListNode* rev_curr = slow;
        while(rev_curr) {
            ListNode* rev_next = rev_curr->next;
            rev_curr->next = rev_prev;
            rev_prev = rev_curr;
            rev_curr = rev_next;
        }

        // finally, reorder nodes
        ListNode* head2 = head;
        while(head2 && rev_prev) {
            ListNode* temp = head2->next;
            ListNode* rev_temp = rev_prev->next;
            head2->next = rev_prev;
            head2 = temp;
            rev_prev->next = head2;
            rev_prev = rev_temp;
        }
    }
};
