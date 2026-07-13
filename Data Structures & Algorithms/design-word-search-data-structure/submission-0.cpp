class WordDictionary {
    struct Node {
        vector<Node*> nodes;
        bool isWord;
        Node() {
            nodes.resize(26);
            isWord = false;
        }
    };
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for(char c : word) {
            if(curr->nodes[c-'a'] == nullptr) {
                Node* n = new Node();
                curr->nodes[c-'a'] = n;
                curr = n;
            }
            else {
                curr = curr->nodes[c-'a'];
            }
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        queue<pair<Node*, int>> bfs;
        bfs.push({root, 0});

        while(!bfs.empty()) {
            auto top = bfs.front();
            bfs.pop();
            int ind = top.second;
            Node* n = top.first;
            if(n == nullptr) {
                continue;
            }
            if(ind > word.size()) {
                continue;
            }
            if(ind == word.size()) {
                if(n->isWord == true) {
                    return true;
                }
                continue;
            }

            if(word[ind] == '.') {
                for(int i = 0; i < 26; i++) {
                    bfs.push({n->nodes[i], ind+1});
                }
            }
            else {
                bfs.push({n->nodes[word[ind] - 'a'], ind+1});
            }
        }

        return false;
    }
};
