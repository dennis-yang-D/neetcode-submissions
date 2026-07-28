class Solution {
public:
    vector<int> ans;
    vector<int> curr;
    vector<vector<int>> preqs;
    vector<bool> visited;
    vector<bool> path;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // cycle detection w/ array
        preqs.resize(numCourses);
        visited.resize(numCourses);
        path.resize(numCourses);
        for(auto v : prerequisites) {
            preqs[v[0]].push_back(v[1]);
        }

        for(int i = 0; i < preqs.size(); i++) {
            if(!backtrack(numCourses, i)) {
                return {}; // this means there was a cycle so it must fail
            }
        }

        return ans;
    }

    bool backtrack(int numCourses, int currCourse) {
        if(visited[currCourse]) {
            return false; // fail on cycle detection
        }
        if(path[currCourse]) { // if it's already in the path, continue
            return true;
        }
        visited[currCourse] = true;

        for(int c : preqs[currCourse]) {
            if(!backtrack(numCourses, c)) {
                return false; // fail on cycle detection
            }
        }
        visited[currCourse] = false;

        // If cycle detection is successful, we now want to build the topological ordering
        if(path[currCourse]) {
            return true;
        }
        path[currCourse] = true; // mark this true so we don't place it into the path again
        ans.push_back(currCourse);
        return true; // successfully generated a solution
    }
};
