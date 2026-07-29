class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // cycle detection
        if(n==1 && edges.size() == 0) {
            return true;
        }
        vector<vector<int>> adj_list(n);
        vector<bool> visited(n); // 2 corresponds to visited bc its undirected
        unordered_set<int> pairVisited; // corresponds to if an edge has been visited

        for(int i = 0; i < edges.size(); i++) {
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);
        }

        stack<int> dfs;
        for(int i = 0; i < n; i++) {
            if(adj_list[i].size() > 0) {
                dfs.push(i);
                break;
            }
        }

        while(!dfs.empty()) {
            int t = dfs.top();
            dfs.pop();

            if(visited[t]) {return false;}
            visited[t] = true;
            for(int i : adj_list[t]) {
                if(pairVisited.contains(1000*t + i) || pairVisited.contains(1000*i + t)) {
                    continue;
                }
                dfs.push(i);
                pairVisited.insert(1000*t + i);
                pairVisited.insert(1000*i + t);
            }
        }

        for(bool b : visited) {
            if(!b) {return false;}
        }

        return true;
    }
};
