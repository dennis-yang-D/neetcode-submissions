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
    bool isValidBST(TreeNode* root) {
        return helper(root, -100000, 100000);
    }

    // left is min value of subtree, right is max value of subtree
    bool helper(TreeNode* root, int left, int right) {
        if(!root) {return true;}

        if(left < root->val && root->val < right) {
            return helper(root->right, root->val, right) && helper(root->left, left, root->val);
        }

        return false; // don't need to go further once you know it's invalid
    }
};
