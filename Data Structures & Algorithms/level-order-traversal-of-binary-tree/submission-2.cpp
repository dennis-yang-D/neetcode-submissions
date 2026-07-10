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
    // DFS solution
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        helper(root, ans, 0);
        return ans;
    }

    void helper(TreeNode* node, vector<vector<int>>& vec, int depth) {
        if(!node) {return;}
        if(depth >= vec.size()) { // should be ok if we just push since future calls will always
        // have the extra vector
            vec.push_back({node->val});
        }
        else {
            vec[depth].push_back(node->val);
        }
        helper(node->left, vec, depth+1);
        helper(node->right, vec, depth+1); // must visit left and then right to get the right order
    }
};
