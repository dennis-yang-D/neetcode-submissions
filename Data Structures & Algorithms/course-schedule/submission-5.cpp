class Solution {
public:
    vector<vector<int>> preqs; // once you take v[0], then its a vector of which you can take
    vector<int> num_preqs; // number of courses that v[1] has
    vector<bool> visited;
    bool can = true;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // dfs on every node that has no preqs
        // see if you can dfs every course without cycles
        // it's actually just a cycle detection problem, basically only need a visited array
        preqs.resize(numCourses);
        visited.resize(numCourses);
        for(auto v : prerequisites) {
            preqs[v[1]].push_back(v[0]);
        }

        for(int i = 0; i < preqs.size(); i++) {
            dfs(i);
        }

        return can;
    }

    void dfs(int currCourse)
    {
        for(int v : preqs[currCourse]) {
            if(visited[v]) {
                can = false;
                return; // don't bother traversing bc its a cycle
            }
            visited[v] = true;
            currCourse++;
            dfs(v);
            currCourse--;
            visited[v] = false;
        }
    }
};
