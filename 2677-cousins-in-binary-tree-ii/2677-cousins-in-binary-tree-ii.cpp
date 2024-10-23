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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return nullptr;

        vector<int>total_sum;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int temp = 0;
            while (size--) {
                auto curr= q.front();
                temp +=curr->val;
                q.pop();
                if(curr->left !=NULL) q.push(curr->left);
                if(curr->right !=NULL) q.push(curr->right);
            }
            total_sum.push_back(temp);                
        }

        q.push(root);
        root->val=0;
        int i=0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto curr=q.front();
                int sum=0;
                q.pop();
                if(curr->left) sum +=curr->left->val;
                if(curr->right) sum +=curr->right->val;
                if(curr->left){
                    curr->left->val=total_sum[i+1]-sum;
                    q.push(curr->left);
                }
                if(curr->right){
                    curr->right->val=total_sum[i+1]-sum;
                    q.push(curr->right);
                }
            }
            i++;               
        }
        return root;
    }
};