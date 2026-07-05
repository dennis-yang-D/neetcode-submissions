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
    struct comp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;

        for(ListNode* i : lists) {
            pq.push(i);
        }

        ListNode* head = new ListNode();
        ListNode* curr = head;

        while(!pq.empty()) {
            ListNode* top = pq.top();
            pq.pop();
            ListNode* next = top->next;
            //cout << next;
            top->next = nullptr;
            curr->next = top;
            curr = curr->next;

            if(next) {
                pq.push(next);
            }
        }

        return head->next;
    }
};
