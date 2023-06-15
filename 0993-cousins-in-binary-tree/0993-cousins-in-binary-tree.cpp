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
    int x_d,y_d,x_p,y_p;
    void depth(TreeNode* root,int x,int y,int d,int parent){
        if(root==NULL){
            return ;
        }
        if(root->val==x){
            x_d=d;
            x_p=parent;
            return;
        }
        if(root->val==y){
            y_d=d;
            y_p=parent;
            return;
        }
        depth(root->left,x,y,d+1,root->val);
        depth(root->right,x,y,d+1,root->val);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        depth(root,x,y,0,0);
        if(x_d==y_d && x_p!=y_p)return 1;
        return 0;
    }
};