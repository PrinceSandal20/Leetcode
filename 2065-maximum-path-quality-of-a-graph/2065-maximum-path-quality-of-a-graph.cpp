class Solution {
public:
    void dfs(int node,int score,int time,vector<int>&value,int &ans,int maxtime,unordered_map<int,vector<pair<int,int>>>&m,vector<int>&vis){
        if(time>maxtime){
            return;
        }
        if(vis[node]==0){
            score+=value[node];
        }
        vis[node]++;
        if(node==0){
            ans=max(ans,score);
        }
        for(auto val:m[node]){
            int u=val.first;
            int t=val.second;
            dfs(u,score,time+t,value,ans,maxtime,m,vis);
        }
        vis[node]--;
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        unordered_map<int,vector<pair<int,int>>>m;
        vector<int>vis(values.size(),0);
        int ans=0;
        for(int i=0;i<edges.size();i++){
            m[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            m[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        dfs(0,0,0,values,ans,maxTime,m,vis);
        return ans;
    }
};