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
    void dfs(TreeNode* root,bool dir,int steps){
        if(root==NULL){
            return;
        }
        ans=max(ans,steps);
        if(dir){
            dfs(root->left,false,steps+1);
            dfs(root->right,true,1);
        }
        else{
            dfs(root->right,true,steps+1);
            dfs(root->left,false,1);
        }
    }
    int longestZigZag(TreeNode* root) {
        dfs(root,true,0);
        dfs(root,false,0);
        return ans;
    }
};