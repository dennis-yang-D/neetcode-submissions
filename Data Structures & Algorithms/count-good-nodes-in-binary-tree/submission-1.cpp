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
    int goodNodes(TreeNode* root) {
        // BFS

        unordered_map<TreeNode*, int> max_map;
        queue<TreeNode*> bfs;
        int num_good = 0;
        bfs.push(root);
        max_map[root] = root->val;

        while(!bfs.empty()) {
            TreeNode* curr = bfs.front();
            bfs.pop();

            if(!curr) {continue;}
            if(max_map[curr] <= curr->val) {
                num_good++;
            }

            max_map[curr->left] = max(max_map[curr], curr->val);
            max_map[curr->right] = max(max_map[curr], curr->val);
            bfs.push(curr->left);
            bfs.push(curr->right);
        }

        return num_good;
    }
};
