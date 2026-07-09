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
    // Base case: if both are nullptr, return true
    // Base case: if root is nullptr but subroot is not nullptr, return false

    // Idea: The leaves of the root and subroot must be the same. Once we establish that,
    // we can move upwards in the tree and compare there
    // So the nodes must have the same structure to be correct
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) {return true;}
        if((!root && subRoot) || (root && !subRoot)) {
            return false;
        }
        return sameTree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool sameTree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) {return true;}
        if((!root && subRoot) || (root && !subRoot)) {
            return false;
        }
        return (root->val == subRoot->val) && sameTree(root->left, subRoot->left) && sameTree(root->right, subRoot->right);
    }
};
