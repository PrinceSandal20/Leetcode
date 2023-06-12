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
    int ans=0;
    void dfs(TreeNode* root,TreeNode* parent,TreeNode* GrandParent){
        if(root==NULL){
            return;
        }
        if(GrandParent!=NULL && (GrandParent->val)%2==0){
            ans+=root->val;
        }
        if(parent==NULL && GrandParent==NULL){
            dfs(root->left,root,GrandParent);
            dfs(root->right,root,GrandParent);
        }
        if((parent!=NULL && GrandParent==NULL) || parent!=NULL && GrandParent!=NULL){
            dfs(root->left,root,parent);
            dfs(root->right,root,parent);
        }
    }
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root,NULL,NULL);
        return ans;
    }
};