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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Iterative solution

        queue<pair<TreeNode*, TreeNode*>> bfs;

        bfs.push({p, q});
        while(!bfs.empty()) {
            auto b = bfs.front();
            bfs.pop();

            if((b.first && !b.second) || (b.second && !b.first)) {
                return false;
            }
            if(b.first && b.second) {
                if(b.first->val != b.second->val) {
                    return false;
                }
                bfs.push({b.first->left, b.second->left});
                bfs.push({b.first->right, b.second->right});
            }
        }

        return true;
    }
};
