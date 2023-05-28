class Solution {
public:
    void dfs(int node,int count,int &ans,vector<int>adj[],vector<int>&vis,vector<int>&path){
        vis[node]=1;
        path[node]=1;
        for(auto val:adj[node]){
            if(!vis[val]){
                dfs(val,count+1,ans,adj,vis,path);
            }
            else if(path[val]){
                ans=max(ans,count);
            }
        }
        path[node]=0;
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            if(edges[i]!=-1){
                adj[edges[i]].push_back(i);
            }
        }
        int ans=-1;
        vector<int>vis(n,0),path(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
               dfs(i,1,ans,adj,vis,path);
            }
        }
        return ans;
    }
};