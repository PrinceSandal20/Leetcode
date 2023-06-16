class Solution {
public:
    vector<int> dfs(int node,int parent,vector<int>adj[],string &labels,vector<int>&ans){
        vector<int>map(26,0);
        map[labels[node]-'a']=1;
        for(auto child:adj[node]){
            if(child!=parent){
                vector<int>res=dfs(child,node,adj,labels,ans);
                for(int i=0;i<26;i++){
                     map[i]=map[i]+res[i];
                }
            }
        }
        ans[node]=map[labels[node]-'a'];
        return map;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>ans(n,0);
        dfs(0,-1,adj,labels,ans);
        return ans;
    }
};