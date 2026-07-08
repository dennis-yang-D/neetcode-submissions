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
    bool isBalanced(TreeNode* root) {
        bool b = false;
        helper(root, b);
        return b;
    }

    int helper(TreeNode* root, bool& isBalanced) {
        if(!root) {
            isBalanced = true;
            return 0;
        }

        bool lb = false;
        bool rb = false;

        int l = helper(root->left, lb);
        int r = helper(root->right, rb);

        isBalanced = lb && rb && ((l-r <= 1) && (r-l) <= 1);
        return 1 + max(l, r);
    }
};
