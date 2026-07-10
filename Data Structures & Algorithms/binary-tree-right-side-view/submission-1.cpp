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
    vector<int> rightSideView(TreeNode* root) {
        // same as Level order traversal, but then you can always take the right most node

        queue<TreeNode*> bfs;
        vector<int> ans;
        bfs.push(root);

        while(!bfs.empty()) {
            int size = bfs.size();
            optional<int> last_val;
            for(int i = 0; i < size; i++) {
                TreeNode* curr = bfs.front();
                bfs.pop();
                if(!curr) {continue;}
                last_val = curr->val;
                bfs.push(curr->left); // always do left first for correct order
                bfs.push(curr->right);
            }

            if(last_val.has_value()) {
                ans.push_back(last_val.value());
            }
        }

        return ans;
    }
};
