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
    bool dfs(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            return root->val;
        }
        bool a;
        if(root->val==2){
             a= dfs(root->left) || dfs(root->right);
        }
        if(root->val==3){
            a = dfs(root->left) && dfs(root->right); 
        }
        return a;
    }
    bool evaluateTree(TreeNode* root) {
        return dfs(root);
    }
};