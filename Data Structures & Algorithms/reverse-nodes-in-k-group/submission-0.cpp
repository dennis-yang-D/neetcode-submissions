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

 // Head->1->2->3->4->5
 // prev points to head, curr points to 1

 // We increment group to 3
 // Reverse, set curr to 2 (since we increment all the way)
 // Set prev->next = curr
 // Then, set prev = curr, and curr to curr->next

 // curr marks the end of a group of k nodes, which gets flipped after the reverse. prev marks the end of the last group of k nodes.

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* head2 = new ListNode(0, head);
        //count nodes
        ListNode* prev = head2;
        ListNode* curr = head;

        bool first = true;
        while(true)
        {
            // two groups - k nodes for reversal, then go k more to find the next head
            //cout << curr->val << " ";
            ListNode* group = curr;
            int num_nodes = 0;
            for(int i = 0; i < k; i++) {
                if(!group) {
                    break;
                }
                num_nodes++;
                group = group->next;
            }
            ListNode* start_group_ptr = nullptr;
            if(num_nodes == k) {
                start_group_ptr = reverseNodes(curr, k); // now points to the start of the group of k nodes
            }
            else {
                break; // do not reverse
            }

            prev->next = start_group_ptr;
            prev = curr;
            curr = curr->next;
        }

        return head2->next;
    }

    ListNode* reverseNodes(ListNode* head, int k) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        for(int i = 0; i < k-1; i++) {
            if(!curr) {break;}
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = curr; // start of next group of k nodes

        return prev; // This marks the end of the group of k nodes
    }
};

