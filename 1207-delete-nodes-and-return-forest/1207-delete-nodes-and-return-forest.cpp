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
    TreeNode* dfs(TreeNode* root, set<int>& s, vector<TreeNode*>& v) {
        if (root == NULL) {
            return NULL;
        }

        root->left = dfs(root->left, s, v);
        root->right = dfs(root->right, s, v);

        if (s.find(root->val) != s.end()) {
            if (root->left != NULL) {
                v.push_back(root->left);
            }
            if (root->right != NULL) {
                v.push_back(root->right);
            }
            delete root;
            return NULL;
        }
        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> s(to_delete.begin(), to_delete.end());
        vector<TreeNode*> v;
        root = dfs(root, s, v);
        if (root != NULL) {
            v.push_back(root);
        }
        return v;
    }
};
