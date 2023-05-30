class Solution {
public:
    void dfs(int node,int parent,int count,int &ans,vector<int>adj[],vector<int>&vis){
        vis[node]=count;
        for(auto val:adj[node]){
            if(val!=parent){
                if(vis[val]>count){
                    dfs(val,node,count+1,ans,adj,vis);
                }
                else if(vis[val]<count-1){
                    ans=min(ans,count-vis[val]+1);
                }
            }
        }
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int ans=1e9;
        vector<int>vis(n,INT_MAX);
        for(int i=0;i<n;i++){
            if(vis[i]==INT_MAX){
                dfs(i,-1,0,ans,adj,vis);
            }
        }
        if(ans==1e9){
            return -1;
        }
        return ans;
    }
};