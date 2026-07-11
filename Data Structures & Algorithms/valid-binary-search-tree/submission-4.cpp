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
    bool is_bst = true;
    bool isValidBST(TreeNode* root) {
        helper(root);
        return is_bst;
    }

    // left is min value of subtree, right is max value of subtree
    pair<int, int> helper(TreeNode* root) {
        if(!root) {return {-10000, -10000};}
        if(!root->left && !root->right) {
            return {root->val, root->val};
        }
        auto p1 = helper(root->left);
        auto p2 = helper(root->right);
        int minLeft = 0;
        int maxLeft = 0;
        if(p1.first != -10000 && p2.first != -10000)
        {if(!(p1.second < root->val && root->val < p2.first)) {
            // if not valid
            is_bst = false;
        }
        minLeft = min(p1.first, min(root->val, p2.first));
        maxLeft = max(p1.second, max(root->val, p2.second));}
        else if(p1.first != -10000) {
            if(!(p1.second < root->val)) {
            // if not valid
                is_bst = false;
            }
            minLeft = min(p1.first, root->val);
            maxLeft = max(p1.second, root->val);
        } else {
            if(!(root->val < p2.first)) {
            // if not valid
                is_bst = false;
            }
            minLeft = min(p2.first, root->val);
            maxLeft = max(p2.second, root->val);
        }

        return {minLeft, maxLeft};
    }
};
