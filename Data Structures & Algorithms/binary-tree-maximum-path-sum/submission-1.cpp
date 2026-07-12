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
    // similar to longest path in binary tree?
    // Longest path that goes through node n is max of:
    // Longest path on n->left, longest path on n->right
    // longest n-end paths on left + n, longest n-end paths on right + n
    // longest n-end paths on left + n-end on right + n

    // step one: calculate length of paths that start from the root node n

    unordered_map<TreeNode*, int> sum_map;
    
    int maxPathSum(TreeNode* root) {
        sum_map[nullptr] = -10000000;
        sumHelper(root);
        return findMaxPath(root);
    }
    
    int sumHelper(TreeNode* root) {
        if(!root) {-10000000;}
        if(sum_map.contains(root)) {return sum_map[root];}

        sum_map[root] = root->val + max(sumHelper(root->left), max(sumHelper(root->right), 0));
        return sum_map[root];
    }

    int findMaxPath(TreeNode* root) {
        if(!root) {return -10000000;}

        int leftPath = sum_map[root->left]; // this path must end at root->left
        int rightPath = sum_map[root->right];

        int leftPath2 = findMaxPath(root->left); // This path does not have to end at root->left
        int rightPath2 = findMaxPath(root->right);
        
        int leftPath3 = leftPath + root->val; // This path must include the root node
        int rightPath3 = rightPath + root->val;

        int fullPath = leftPath + rightPath + root->val;

        int mLeft = max(leftPath, max(leftPath2, leftPath3));
        int mRight = max(rightPath, max(rightPath2, rightPath3));

        return max(mLeft, max(mRight, max(fullPath, root->val)));
    }
};
