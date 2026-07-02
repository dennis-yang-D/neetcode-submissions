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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow_prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }

        while(fast) {
            fast = fast->next;
            slow_prev = slow;
            slow = slow->next;
        }

        if(!slow_prev) {
            return head->next;
        }

        slow_prev->next = slow->next;
        slow->next = nullptr;
        return head;
    }
};
