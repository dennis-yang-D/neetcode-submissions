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
    int num_good = 0;
    int goodNodes(TreeNode* root) {
        helper(root, root->val);

        return num_good;
    }

    void helper(TreeNode* node, int m) {
        if(!node) {return;}
        if(node->val >= m) {
            num_good++;
        }
        int new_max = max(m, node->val);
        helper(node->left, new_max);
        helper(node->right, new_max);
    }
};
