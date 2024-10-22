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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int len=q.size();
            long long temp=0;
            while(len--){
                auto x=q.front();
                temp +=x->val;
                q.pop();
                if(x->left !=NULL) q.push(x->left);
                if(x->right !=NULL) q.push(x->right);
            }
            v.push_back(temp);
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());

        return v.size() <k?-1:v[k-1];
    }
};