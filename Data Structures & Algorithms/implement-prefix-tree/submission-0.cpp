class PrefixTree {
    struct Node {
        vector<pair<Node*, string>> nodes;
        Node() {
            nodes.resize(26);
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
            if(curr->nodes[c - 'a'].first == nullptr) {
                Node* temp = new Node();
                curr->nodes[c - 'a'].first = temp;
                curr = temp;
            }
            else {
                curr = curr->nodes[c - 'a'].first;
            }
        }
        char c = word[word.size()-1];
        curr->nodes[c - 'a'].second = word;
    }
    
    bool search(string word) {
        Node* curr = head;
        for(char c : word) {
            if(curr->nodes[c - 'a'].first == nullptr) {
                return false;
            }
            else {
                curr = curr->nodes[c - 'a'].first;
            }
        }

        char c = word[word.size()-1];
        if(curr->nodes[c-'a'].second == "") {return false;}
        return true;
    }
    
    bool startsWith(string prefix) {
        Node* curr = head;
        for(char c : prefix) {
            if(curr->nodes[c - 'a'].first == nullptr) {
                return false;
            }
            else {
                curr = curr->nodes[c - 'a'].first;
            }
        }

        return true;
    }
};
