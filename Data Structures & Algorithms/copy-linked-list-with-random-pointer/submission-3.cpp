/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) {return head;}
        // Space Optimized - no hashmap
        Node* temp = head;

        // first make a duplicate of each node and adjust ptrs
        // so 1 -> 2 -> 3 -> null becomes 1 -> 1 -> 2 -> 2 -> 3 -> 3 -> null
        while(temp) {
            Node* copy = new Node(temp->val);
            Node* next = temp->next;
            temp->next = copy;
            copy->next = next;
            temp = next;
        }

        // adj random pointer -> lets say 1 points to 3. Then, 1's copy should point to 3's copy
        // since 3's copy is 3's next, we can take 1->random, then take its next ptr.
        temp = head;

        while(temp) {
            Node* temp_next = temp->next;
            if(!temp->random) {
                temp_next->random = nullptr;
            }
            else
            {temp_next->random = temp->random->next;}
            temp = temp->next->next;
        }

        // finally, take the copy nodes and adjust their nexts to skip over the original nodes
        temp = head;
        Node* new_head = temp->next;
        while(temp) {
            Node* temp_next = temp->next;
            temp->next = temp_next->next;
            
            if(temp->next) {
                temp_next->next = temp_next->next->next;
            }
            temp = temp->next;
        }

        return new_head;
    }
};
