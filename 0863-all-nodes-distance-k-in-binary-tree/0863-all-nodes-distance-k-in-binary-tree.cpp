/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<int,vector<int>>m;
    vector<int>ans;
    void buildgraph(TreeNode* root,TreeNode* parent){
        if(root==NULL){
            return ;
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
    void bfs(TreeNode* target,int k){
        if(k==0){
            ans.push_back(target->val);
        }
        map<int,int>vis;
        queue<pair<int,int>>q;
        vis[target->val]=1;
        q.push({0,target->val});
        while(!q.empty()){
            int depth=q.front().first;
            int node=q.front().second;
            q.pop();
            for(auto val:m[node]){
                if(!vis[val]){
                    vis[val]=1;
                    q.push({depth+1,val});
                    if(depth+1==k){
                        ans.push_back(val);
                    }
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildgraph(root,NULL);
        bfs(target,k);
        return ans;
    }
};