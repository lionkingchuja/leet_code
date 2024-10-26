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
    int ma;
    void findleft(TreeNode* root,vector<int>&left,int d){
        if(root==NULL) return;
        left[root->val]=ma;
        ma=max(ma,d);
        findleft(root->left,left,d+1);
        findleft(root->right,left,d+1);
    }
    void findright(TreeNode* root,vector<int>&right,int d){
        if(root==NULL) return;
        right[root->val]=ma;
        ma=max(ma,d);
        findright(root->right,right,d+1);
        findright(root->left,right,d+1);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int>left(100000+6);
        vector<int>right(100000+6);
        ma=0;
        findleft(root,left,0);
        ma=0;
        findright(root,right,0);
        vector<int>ans;
        for(auto i:queries){
            ans.push_back(max(left[i],right[i]));
        }
        return ans;
    }
};