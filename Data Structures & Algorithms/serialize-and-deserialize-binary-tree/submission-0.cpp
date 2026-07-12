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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //from left to right on each level
        // Null ptrs will be serialized as "null"

        queue<TreeNode*> bfs;
        bfs.push(root);
        string ans;

        while(!bfs.empty()) {
            TreeNode* top = bfs.front();
            bfs.pop();

            if(top) {
                ans += to_string(top->val) + ",";
                bfs.push(top->left);
                bfs.push(top->right);
            }
            else {
                ans += "n,";
            }

        }   
        
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // We will keep a vector with the existing nodes at each layer
        // Parse the root node, then parse remaining nodes 2 at a time

        int i = 0;
        TreeNode* root = parseString(data, i);
        vector<TreeNode*> nodes;
        vector<TreeNode*> new_nodes;
        nodes.push_back(root);
        while(i < data.size()) {
            for(int j = 0; j < nodes.size(); j++) {
                // parse 2 nodes at a time
                TreeNode* left = parseString(data, i);
                TreeNode* right = parseString(data, i);
                nodes[j]->left = left;
                nodes[j]->right = right;
                if(left) {new_nodes.push_back(left);}
                if(right) {new_nodes.push_back(right);} // so our nodes array never has nullptr
            }
            nodes = new_nodes;
            new_nodes.clear();
        }

        return root;
    }

    TreeNode* parseString(string& data, int& i) {
        TreeNode* root;
        if(data[i] == 'n') {
            root = nullptr;
            i = i + 2;
        }
        else {
            int val = 0;
            for(;i < data.size(); i++) {
                if(data[i] == ',') {
                    i++;
                    break;
                }
                val = 10*val + data[i] - '0';
            }
            root = new TreeNode(val);
        }
        return root;
    }
};
