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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        int n = desc.size();
        set<int> s;
        map<int, TreeNode*> m;
        
        for (int i = 0; i < n; i++) {
            // Parent node
            if (m.find(desc[i][0]) == m.end()) {
                m[desc[i][0]] = new TreeNode(desc[i][0]);
            }
            // Child node
            if (m.find(desc[i][1]) == m.end()) {
                m[desc[i][1]] = new TreeNode(desc[i][1]);
            }
            // Set left or right child
            if (desc[i][2] == 1) {
                m[desc[i][0]]->left = m[desc[i][1]];
            } else {
                m[desc[i][0]]->right = m[desc[i][1]];
            }
            s.insert(desc[i][1]);
        }
        
        for (int i = 0; i < n; i++) {
            if (s.find(desc[i][0]) == s.end()) {
                return m[desc[i][0]];
            }
        }
        return NULL;
    }
};
