/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        vector<vector<int>> adj_list(101);

        stack<Node*> dfs;
        unordered_map<Node*, bool> visited;

        dfs.push(node);
        while(!dfs.empty()) {
            Node* t = dfs.top();
            dfs.pop();
            if(!t) {continue;}
            if(visited[t]) {continue;}
            visited[t] = true;

            for(Node* n : t->neighbors) {
                adj_list[t->val].push_back(n->val);
                adj_list[n->val].push_back(t->val);
                dfs.push(n);
            }
        }

        vector<Node*> newNodes(101);
        for(int i = 0; i < 101; i++) {
            newNodes[i] = new Node(i);
        }

        for(int i = 0; i < 101; i++) {
            unordered_set<int> i_vals;
            for(int n : adj_list[i]) {
                if(i_vals.contains(n)) {continue;}
                i_vals.insert(n);

                newNodes[i]->neighbors.push_back(newNodes[n]);
            }
        }

        if(node == nullptr) {return node;}
        return newNodes[1];
    }
};
