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

        queue<TreeNode*>q;
        q.push(root);
        int prev=0;
        root->val=0;
        while(!q.empty()){
            int size = q.size();
            int level_sum = 0;
            while (size--){
                auto curr= q.front();
                curr->val=prev-curr->val;// curr val updation
                int temp=0;
                if(curr->left) temp +=curr->left->val;
                if(curr->right) temp +=curr->right->val;
                level_sum +=temp;
                q.pop();
                if(curr->left !=NULL) {
                    curr->left->val=temp;// root node ko update
                    q.push(curr->left);
                }
                if(curr->right !=NULL){
                    curr->right->val=temp;// root node ko update
                    q.push(curr->right);
                }
            }
            prev=level_sum;                
        }

       
        return root;
    }
};