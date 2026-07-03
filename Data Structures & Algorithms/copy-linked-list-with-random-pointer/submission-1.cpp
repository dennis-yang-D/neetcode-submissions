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
        if(!head) {return nullptr;}
        vector<Node*> old_node_vec;
        vector<Node*> new_node_vec;

        unordered_map<Node*, int> node_map;

        Node* temp = head;
        node_map[nullptr] = -1;
        while(temp) {
            node_map[temp] = old_node_vec.size();
            old_node_vec.push_back(temp);
            Node* new_node = new Node(temp->val);
            new_node_vec.push_back(new_node);
            temp = temp->next;
        }

        for(int i = 0; i < old_node_vec.size()-1; i++) {
            new_node_vec[i]->next = new_node_vec[i+1];
        }

        for(int i = 0; i < old_node_vec.size(); i++) {
            int node_ind = node_map[old_node_vec[i]->random];
            if(node_ind == -1) {
                new_node_vec[i]->random = nullptr;
            }
            else
            {new_node_vec[i]->random = new_node_vec[node_ind];}
        }

        return new_node_vec[0];
    }
};
