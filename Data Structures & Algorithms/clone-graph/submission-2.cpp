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
        vector<Node*> newNodes(101);
        for(int i = 0; i < 101; i++) {
            newNodes[i] = new Node(i);
        }

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
                // we visit every node anyways, so this will insert the correct neighbors
                // for an undirected graph
                newNodes[t->val]->neighbors.push_back(newNodes[n->val]);
                dfs.push(n);
            }
        }

        if(node == nullptr) {return node;}
        return newNodes[1];
    }
};
