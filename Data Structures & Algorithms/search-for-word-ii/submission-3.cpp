class Solution {
    struct Node {
        vector<Node*> nodes;
        bool is_word = false;
        int num_words = 0; // number of words that go through this node
        Node() {
            nodes.resize(26);
        }
    };
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // Make a trie with all of the words

        Node* tree = new Node();
        for(string s : words) {
            Node* curr = tree;
            for(char c : s) {
                if(curr->nodes[c - 'a'] == nullptr) {
                    Node* n = new Node();
                    curr->nodes[c - 'a'] = n;
                }
                curr = curr->nodes[c - 'a'];
                curr->num_words++;
            }
            curr->is_word = true;
        }

        vector<string> ans;

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                unordered_map<int, bool> visited;
                backtrack(tree->nodes[board[i][j] - 'a'], board, i, j, ans, visited, string{board[i][j]});
            }
        }

        return ans;
    }

    void backtrack(Node* curr, vector<vector<char>>& board, int i, int j, vector<string>& m, unordered_map<int, bool>& visited, string s) {
        if(visited[i * 100 + j]) {return;}
        if(curr == nullptr) {return;}
        visited[i * 100 + j] = true;
        if(s == "") {return;}
        if(curr->num_words <= 0) {return;} // Idea from solution: cull the branch if 0 words pass through this node

        if(curr->is_word) {
            m.push_back(s);
            curr->is_word = false;
            curr->num_words--;
        }

        char c;
        string n = "";
        if(i - 1 >= 0) {
            if(!visited[(i - 1) * 100 + j]) {
                c = board[i - 1][j];
                n = s + c;
                backtrack(curr->nodes[c - 'a'], board, i-1, j, m, visited, n);
                visited[(i - 1) * 100 + j] = false;
            }
        }
        if(i + 1 < board.size()) {
            if(!visited[(i + 1) * 100 + j]) {
                c = board[i + 1][j];
                n = s + c;
                backtrack(curr->nodes[c - 'a'], board, i+1, j, m, visited, n);
                visited[(i + 1) * 100 + j] = false;
            }
        }
        if(j - 1 >= 0) {
            if(!visited[(i) * 100 + j - 1]) {
                c = board[i][j - 1];
                n = s + c;
                backtrack(curr->nodes[c - 'a'], board, i, j - 1, m, visited, n);
                visited[i * 100 + j - 1] = false;
            }
        }
        if(j + 1 < board[0].size()) {
            if(!visited[(i) * 100 + j + 1]) {
                c = board[i][j + 1];
                n = s + c;
                backtrack(curr->nodes[c - 'a'], board, i, j+1, m, visited, n);
                visited[(i) * 100 + j + 1] = false;
            }
        }

    }

    pair<bool, Node*> startsWith(Node* head, string word) {
        Node* curr = head;
        for(char c : word) {
            if(curr->nodes[c - 'a'] == nullptr) {
                return {false, nullptr};
            }
            curr = curr->nodes[c - 'a'];
        }

        return {true, curr};
    }
};
