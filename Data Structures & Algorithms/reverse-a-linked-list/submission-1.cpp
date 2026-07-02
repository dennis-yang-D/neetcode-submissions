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
    ListNode* reverseList(ListNode* head) {
        // 1 -> 2 -> 3
        // node A = 1, node B = 2
        // Point B to A
        // Set A to B
        // Increment B

        ListNode* left = nullptr;
        ListNode* right = head;

        while(right) {
            ListNode* next = right->next;
            right->next = left;
            left = right;
            right = next;
        }

        return left;
    }
};
