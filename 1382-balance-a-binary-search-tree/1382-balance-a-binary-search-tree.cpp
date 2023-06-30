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
    void inorder(TreeNode* root,vector<int>&res){
        if(root==NULL)return;
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }
    TreeNode* makebst(int i,int j,vector<int>&res){
        if(i>j)return NULL;
        int mid=i+(j-i)/2;
        TreeNode* ans=new TreeNode(res[mid]);
        ans->left=makebst(i,mid-1,res);
        ans->right=makebst(mid+1,j,res);
        return ans;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>res;
        inorder(root,res);
        int x=res.size();
        return makebst(0,x-1,res);
    }
};