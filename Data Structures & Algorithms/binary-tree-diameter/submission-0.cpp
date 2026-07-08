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
    int diameterOfBinaryTree(TreeNode* root) {
        int diam  = 0;
        helper(root, diam);

        return diam;
        // Diameter: height on left + height on right
    }

    // Goal: function that calculates the height of each node AND the diameter
    int helper(TreeNode* root, int& diam) {
        if(root == nullptr) {return 0;}
        int l = helper(root->left, diam);
        int r = helper(root->right, diam);
        diam = max(diam, l + r);
        return 1 + max(l, r);
    }
};
