class Solution {
public:
    vector<unordered_set<int>> adj;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // find the cycle within the tree
        adj.resize(edges.size() + 1);
        for(auto v : edges) {
            adj[v[0]].insert(v[1]);
            adj[v[1]].insert(v[0]);
        }

        vector<int> e;

        for(int i = edges.size() - 1; i > -1; i--) {
            vector<int> v = edges[i];
            int start = 1;
            adj[v[0]].erase(v[1]);
            adj[v[1]].erase(v[0]);
            if(!e.empty()) {
                adj[e[0]].insert(e[1]);
                adj[e[1]].insert(e[0]);
                start = e[0];
            }
            e = v;
            unordered_set<int> pairHash;
            stack<pair<int, int>> dfs; // store prev and curr
            vector<int> visited(edges.size()+1);

            dfs.push({0, start});
            bool has_cycle = false;
            while(!dfs.empty()) {
                auto t = dfs.top();
                dfs.pop();

                cout << t.first << " " << t.second << endl;

                if(pairHash.contains(t.first * 1000 + t.second) || pairHash.contains(t.second * 1000 + t.first)) {
                    continue;
                }
                if(visited[t.second]) {
                    has_cycle = true;
                    break;
                }
                visited[t.second] = true;
                pairHash.insert(t.first * 1000 + t.second);
                for(int n : adj[t.second]) {
                    dfs.push({t.second, n});
                }
            }
            cout << endl;

                if(!has_cycle) {
                    return e;
                }
            }

        return {0,0};
    }
};
