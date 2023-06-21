class Solution {
public:
    int timer=1;
    void dfs(int node,int parent,vector<int>adj[],vector<int>&vis,int time[],int low[],vector<vector<int>>&bridges){
        vis[node]=1;
        time[node]=low[node]=timer++;
        for(auto val:adj[node]){
            if(val==parent) continue;
            if(!vis[val]){
                dfs(val,node,adj,vis,time,low,bridges);
                low[node]=min(low[node],low[val]);
                if(low[val]>time[node]){
                    bridges.push_back({val,node});
                }
            }
            else{
                low[node]=min(low[node],low[val]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<vector<int>>bridges;
        vector<int>vis(n,0);
        int time[n],low[n];
        dfs(0,-1,adj,vis,time,low,bridges);
        return bridges;
    }
};