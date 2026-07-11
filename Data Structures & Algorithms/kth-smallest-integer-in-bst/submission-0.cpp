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
    // accomplish w/ inorder traversal
    // so visit left, then middle, then right
    int ans = 0;
    int kthSmallest(TreeNode* root, int k) {
        int curr = 1;
        traverse(root, curr, k);
        return ans;
    }

    void traverse(TreeNode* root, int& curr, int k) {
        if(!root) {return;}
        traverse(root->left, curr, k);

        if(curr == k) {
            ans = root->val;
            curr++;
            return;
        }
        curr++;
        traverse(root->right, curr, k);
    }
};
