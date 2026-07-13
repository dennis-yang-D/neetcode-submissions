class PrefixTree {
    struct Node {
        vector<Node*> nodes;
        bool endofword;
        Node() {
            nodes.resize(26);
            endofword = false;
        }
    };
public:
    Node* head = nullptr;
    PrefixTree() {
        head = new Node();
    }
    
    void insert(string word) {
        Node* curr = head;
        for(char c : word) {
            if(curr->nodes[c - 'a'] == nullptr) {
                Node* temp = new Node();
                curr->nodes[c - 'a'] = temp;
                curr = temp;
            }
            else {
                curr = curr->nodes[c - 'a'];
            }
        }
        curr->endofword = true;
    }
    
    bool search(string word) {
        Node* curr = head;
        for(char c : word) {
            if(curr->nodes[c - 'a'] == nullptr) {
                return false;
            }
            else {
                curr = curr->nodes[c - 'a'];
            }
        }

        return curr->endofword;
    }
    
    bool startsWith(string prefix) {
        Node* curr = head;
        for(char c : prefix) {
            if(curr->nodes[c - 'a'] == nullptr) {
                return false;
            }
            else {
                curr = curr->nodes[c - 'a'];
            }
        }

        return true;
    }
};
