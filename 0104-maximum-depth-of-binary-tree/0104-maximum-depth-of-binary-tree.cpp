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
    int solve(TreeNode* root,int height){
        if(root==NULL) return height;
        int left=solve(root->left,height);
        int right=solve(root->right,height);
        return max(left,right)+1;
    }
    int maxDepth(TreeNode* root) {
        int height=0;
        return solve(root,height);
    }
};