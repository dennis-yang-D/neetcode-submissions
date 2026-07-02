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

        // Set this value to a nullptr to disconnect the two halves of the list
        // avoid infinite loop
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
        // [2,4,6,8,10] becomes [2,4,6] and [10,8]
        // 2 then points to 10. 2 advances to 4. 10 points to 4. 10 advances to 8
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
