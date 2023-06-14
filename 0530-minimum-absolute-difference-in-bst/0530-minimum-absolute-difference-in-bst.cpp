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
    int x=-1,mn=INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        
        getMinimumDifference(root->left);
        if(x!=-1)
        {
            mn=min(mn,root->val-x);
        }
        x=root->val;
        getMinimumDifference(root->right);
        return mn;
    }
};