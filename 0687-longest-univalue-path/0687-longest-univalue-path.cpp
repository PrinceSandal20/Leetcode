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
    private:
    int ans=0;
    int dfs(TreeNode* root){
        if(root==NULL)return 0;
        int l=dfs(root->left);
        int r=dfs(root->right);
        int left=0,right=0;
        if(root->left!=NULL && root->val==root->left->val){
            left=1+l;
        }
        if(root->right!=NULL && root->val==root->right->val){
            right=1+r;
        }
        ans=max(ans,left+right);
        return max(left,right);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL)return 0;
        dfs(root);
        return ans;
    }
};