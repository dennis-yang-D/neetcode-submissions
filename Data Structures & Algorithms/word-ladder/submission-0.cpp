class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> adj_list;

        for(int i = 0; i < wordList.size(); i++) {
            if(validDiff(wordList[i], beginWord)) {
                adj_list[wordList[i]].push_back(beginWord);
                adj_list[beginWord].push_back(wordList[i]);
            }
            for(int j = i + 1; j < wordList.size(); j++) {
                if(validDiff(wordList[i], wordList[j])) {
                    adj_list[wordList[i]].push_back(wordList[j]);
                    adj_list[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        // use bfs

        queue<pair<string, int>> bfs;
        bfs.push({beginWord, 1});
        unordered_map<string, bool> visited;

        while(!bfs.empty()) {
            auto t = bfs.front();
            bfs.pop();

            if(visited[t.first]) {continue;}
            if(t.first == endWord) {return t.second;}
            visited[t.first] = true;

            for(string s : adj_list[t.first]) {
                bfs.push({s, t.second + 1});
            }
        }

        return 0;
    }

    bool validDiff(const string& a, const string& b) {
        int num_diff = 0;
        for(int i = 0; i  < a.size(); i++) {
            if(a[i] != b[i]) {
                num_diff++;
            }
            if(num_diff > 1) {return false;}
        }
        if(num_diff == 1) {return true;}
        return false;
    }
};
