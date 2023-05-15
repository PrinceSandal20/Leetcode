class Solution {
public:
    void dfs(int node,vector<int>adj[],vector<int>&vis,int &nod,int &edg){
        vis[node]=1;
        nod++;
        edg+=adj[node].size();
        for(auto val:adj[node]){
            if(!vis[val]){
                dfs(val,adj,vis,nod,edg);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj[n],vis(n,0);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int nod=0,edg=0;
            if(!vis[i]){
               dfs(i,adj,vis,nod,edg);
               if(nod*(nod-1)==edg){
                   ans++;
               }
            }
        }
        return ans;
    }
};