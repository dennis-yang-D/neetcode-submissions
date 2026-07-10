/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        queue<pair<int, TreeNode*>> bfs;
        int current_level = 0;
        bfs.push({current_level, root});
        vector<int> level;
        while(!bfs.empty()) {
            auto p = bfs.front();
            bfs.pop();

            if(current_level < p.first) {
                // don't need the push back outside the loop
                // because current_level will be >= p.first after we hit our nullptr at the end
                // so we push back level, and all future nullptrs will never have a greater level
                current_level++;
                ans.push_back(level);
                level.clear();
            }

            if(!p.second) {
                continue;
            }
            else {
                level.push_back(p.second->val);
            }

            bfs.push({p.first + 1, p.second->left});
            bfs.push({p.first + 1, p.second->right});
        }

        //ans.push_back(level);
        return ans;
    }
};
