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
    // iterative version
    int diameterOfBinaryTree(TreeNode* root) {
        stack<TreeNode*> dfs;
        int diam = 0;
        dfs.push(root);
        unordered_map<TreeNode*, bool> visited;
        unordered_map<TreeNode*, int> heights;

        while(!dfs.empty()) {
            TreeNode* curr = dfs.top();
            //cout << dfs.size() << " ";
            //post order
            if(!curr) {
                dfs.pop();
                continue;
            }
            if(!visited[curr]) {
                dfs.push(curr->right);
                dfs.push(curr->left);
                visited[curr] = true;
                continue;
            }

            //visited[curr] = true;
            dfs.pop();
            heights[curr] = 1 + max(heights[curr->left], heights[curr->right]);
            diam = max(diam, heights[curr->left] + heights[curr->right]);
        }

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
