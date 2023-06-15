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
    int maxLevelSum(TreeNode* root) {
        priority_queue<pair<int,int>> maxH;
        if(root==NULL)
        {
            return 0;
        }
        int k=1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            vector<int> res;
            for(int i=0;i<n;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
                res.push_back(node->val);
            }
            int sum=0;
            for(int i=0;i<res.size();i++)
            {
                sum+=res[i];
            }
            maxH.push({sum,k++});
        }
        int mn=INT_MAX;
        int x=maxH.top().first;
        while(maxH.size()>0)
        {
            if(x==maxH.top().first){
                mn=min(mn,maxH.top().second);
            }
            maxH.pop();
        }
        if(mn==INT_MAX){
            return maxH.top().second;
        }
        return mn;
    }
};