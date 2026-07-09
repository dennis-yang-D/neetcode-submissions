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
    unordered_map<TreeNode*, bool> p_desc;
    unordered_map<TreeNode*, bool> q_desc;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // BFS
        pDesc(root, p);
        qDesc(root, q);
        queue<TreeNode*> bfs;

        bfs.push(root);
        TreeNode* ans = nullptr;

        while(!bfs.empty()) {
            TreeNode* top = bfs.front();
            bfs.pop();

            if(p_desc[top] && q_desc[top]) {
                ans = top;
            }
            if(top) {
                bfs.push(top->left);
                bfs.push(top->right);
            }
        }

        return ans;
    }

    bool pDesc(TreeNode* root, TreeNode* p) {
        if(!root) {p_desc[root] = false; return false;}
        if(p_desc.contains(root)) {
            return p_desc[root];
        }
        p_desc[root] = (root == p) || (pDesc(root->left, p)) || pDesc(root->right, p);
        return p_desc[root];
    }

    bool qDesc(TreeNode* root, TreeNode* q) {
        if(!root) {q_desc[root] = false; return false;}
        if(q_desc.contains(root)) {
            return q_desc[root];
        }
        q_desc[root] = (root == q) || (qDesc(root->left, q)) || qDesc(root->right, q);
        return q_desc[root];
    }
};
