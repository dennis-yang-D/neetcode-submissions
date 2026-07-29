class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj_list(n);
        vector<bool> visited(n);

        for(auto v : edges) {
            adj_list[v[0]].push_back(v[1]);
            adj_list[v[1]].push_back(v[0]);
        }

        int num = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                stack<int> dfs;
                dfs.push(i);

                while(!dfs.empty()) {
                    int t = dfs.top();
                    dfs.pop();

                    if(visited[t]) {continue;}
                    visited[t] = true;
                    for(int i : adj_list[t]) {
                        dfs.push(i);
                    }
                }

                num++;
            }
        }

        return num;
    }
};
