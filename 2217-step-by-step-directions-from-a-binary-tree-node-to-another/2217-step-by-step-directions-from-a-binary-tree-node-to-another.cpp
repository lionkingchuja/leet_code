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
    TreeNode* lowestcommonancestor(TreeNode* root,int p,int q){
    if(root==NULL or root->val==p or root->val==q){
        return root;
    }
    TreeNode* left=lowestcommonancestor(root->left,p,q);
    TreeNode* right=lowestcommonancestor(root->right,p,q);

    //result
    if(left==NULL){
        return right;
    }
    else if(right==NULL){
        return left;
    }
    else{//both left and right are not null, we found our result
        return root;
    }
}

bool dfs(TreeNode* root, int x, string& path, bool rev = 0) {
    if (root == NULL)
        return 0;
    if (root->val == x)
        return 1;

    path += (rev ? 'U' : 'L');
    if (dfs(root->left, x, path, rev)) return 1;
    path.pop_back();

    path += (rev ? 'U' : 'R');
    if (dfs(root->right, x, path, rev)) return 1;
    path.pop_back();

    return 0;
}
    string getDirections(TreeNode* root, int s, int d) {
        TreeNode* lca=lowestcommonancestor(root,s,d);
        string start= "", end= "";
        dfs(lca, s,start, 1);
        dfs(lca, d,end);
        return start+end;
    }
};