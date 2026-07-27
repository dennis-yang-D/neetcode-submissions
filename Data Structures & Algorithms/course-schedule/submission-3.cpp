class Solution {
public:
    vector<vector<int>> preqs; // once you take v[0], then its a vector of which you can take
    vector<int> num_preqs; // number of courses that v[1] has
    vector<bool> visited;
    bool can = true;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // dfs on every node that has no preqs
        // see if you can dfs every course without cycles
        // how to quickly verify? count num visited!
        preqs.resize(numCourses);
        visited.resize(numCourses);
        num_preqs.resize(numCourses);
        for(auto v : prerequisites) {
            preqs[v[1]].push_back(v[0]);
            num_preqs[v[0]]++;
        }
        // count # with zero preqs
        int num_z = 0;
        for(auto v : num_preqs) {
            if(v == 0) {num_z++;}
        }

        for(int i = 0; i < preqs.size(); i++) {
            //cout << preqs[i].size() << " ";
            dfs(numCourses, num_z, i);
        }

        return can;
    }

    void dfs(int numCourses, int currCourses, int currCourse)
    {
        for(int v : preqs[currCourse]) {
            if(visited[v]) {
                can = false;
                return; // don't bother traversing bc its a cycle
            }
            visited[v] = true;
            currCourse++;
            dfs(numCourses, currCourses, v);
            currCourse--;
            visited[v] = false;
        }
    }
};
