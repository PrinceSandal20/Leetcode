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
    unordered_map<int,vector<int>>m;
    void buildgraph(TreeNode* root,TreeNode* parent){
        if(root==NULL){
            return;
        }
        if(root!=NULL){
            if(parent){
                m[root->val].push_back(parent->val);
                m[parent->val].push_back(root->val);
            }
            buildgraph(root->left,root);
            buildgraph(root->right,root);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        buildgraph(root,NULL);
        int ans=-1;
        queue<int>q;
        unordered_map<int,int>vis;
        vis[start]=1;
        q.push(start);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                int node=q.front();
                q.pop();
                for(auto val:m[node]){
                    if(!vis[val]){
                        vis[val]=1;
                        q.push(val);
                    }
                }
            }
            ans++;
        }
        return ans;
    }
};