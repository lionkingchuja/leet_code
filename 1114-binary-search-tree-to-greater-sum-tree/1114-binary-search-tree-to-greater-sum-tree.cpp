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
    int temp=0;
public:
    TreeNode* bstToGst(TreeNode* root) {
        if(root==NULL) return NULL;
        bstToGst(root->right);
        temp +=root->val;
        root->val=temp;
        bstToGst(root->left);
        return root;
    }
};