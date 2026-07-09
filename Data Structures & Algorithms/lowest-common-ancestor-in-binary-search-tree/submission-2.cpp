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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) {
            return nullptr;
        }
        int p_val = p->val;
        int q_val = q->val;
        int r_val = root->val;

        if(r_val >= p_val && r_val <= q_val) {
            return root;
        }
        if(r_val >= q_val && r_val <= p_val) {
            return root;
        }

        if(r_val > p_val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        else {
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};
