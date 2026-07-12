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
        // 0 1 2 3 4 5 6 7 8, then inRight is 9 and inLeft is 0
        // if i = 5, then k = 5 - 0 = 5 (there's 5 elts left of i=5)
        // n = 9 - 5 - 1 = 3 (ther's 3 elts right of i=5)
        int k = i - inLeft;
        int n = inRight - i - 1;

        // bin search
        newRoot->left = helper(preorder, inorder, preLeft+1, preLeft+1+k, inLeft, i); //preLeft gets consumed
        newRoot->right = helper(preorder, inorder, preLeft+1+k, preRight, i+1, inRight); //inorder[i] gets consumed
        return newRoot;
    }
};
