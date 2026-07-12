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
// preorder: middle, left, right
// in order: left, middle, right

// first value of the preorder must be the root node
// Find the root node in the inorder traversal.
//All k nodes on the left must be on the left side, all n nodes on the right must be on the right side
// go back to preorder. Recursively build left tree on the first k nodes, then right tree on remaining n nodes
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int preLeft, int preRight, int inLeft, int inRight) {
        if(preLeft == preRight) {
            return nullptr;
        }
        TreeNode* newRoot = new TreeNode(preorder[preLeft]);
        // find the root node in the inorder
        int i = inLeft;
        for(; i < inRight; i++) {
            if(inorder[i] == preorder[preLeft]) {
                break;
            }
        }

        // Find k and n
        int k = i - inLeft;
        int n = inRight - i - 1;

        // bin search
        newRoot->left = helper(preorder, inorder, preLeft+1, preLeft+1+k, inLeft, i);
        newRoot->right = helper(preorder, inorder, preLeft+1+k, preRight, i+1, inRight);
        return newRoot;
    }
};
