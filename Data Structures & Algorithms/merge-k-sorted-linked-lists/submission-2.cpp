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

// Bucket solution - O(N) time but only works if each value in the linked list is restricted.
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<vector<ListNode*>> vals(2001);

        for(ListNode* l : lists) {
            vals[l->val + 1000].push_back(l);
        }

        ListNode* head = new ListNode();
        ListNode* curr = head;

        for(int i = 0; i < vals.size(); i++) {
            while(!vals[i].empty()) {
                ListNode* temp = vals[i].back();
                vals[i].pop_back();
                ListNode* next = temp->next;
                temp->next = nullptr;
                curr->next = temp;
                curr = curr->next;
                if(next) {
                    vals[next->val + 1000].push_back(next);
                }
            }
        }

        return head->next;
    }
};
