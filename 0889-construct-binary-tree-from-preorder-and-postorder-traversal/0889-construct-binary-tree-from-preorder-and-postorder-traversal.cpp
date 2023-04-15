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
    TreeNode* construct(vector<int>&preorder,int pres,int prend,vector<int>& postorder,int posts,int postend){
        if(pres>prend){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[pres]);
        if(pres==prend){
            return root;
        }
        int postidx=posts;
        while(postorder[postidx]!=preorder[pres+1]){
            postidx++;
        }
        int length=postidx-posts+1;
        root->left=construct(preorder,pres+1,pres+length,postorder,posts,postidx);
        root->right=construct(preorder,pres+length+1,prend,postorder,postidx+1,postend-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return construct(preorder,0,preorder.size()-1,postorder,0,postorder.size()-1);
    }
};