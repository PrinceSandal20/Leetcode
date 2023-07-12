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
    vector<TreeNode*>ans;
    unordered_map<string,int>m;
    string dfs(TreeNode* root){
        if(root==NULL)return "";
        string s="";
        s+=to_string(root->val);
        s+="@";
        string left=dfs(root->left);
        s+=left;
        s+="@";
        string right=dfs(root->right);
        s+=right;
        m[s]++;
        if(m[s]==2){
            ans.push_back(root);
        }
        return s;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }
};