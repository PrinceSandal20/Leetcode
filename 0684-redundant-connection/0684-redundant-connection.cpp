class Solution {
public:
    bool dfs(int start,int parent,vector<int>&vis,map<int,vector<int>>&m){
        if(find(vis.begin(),vis.end(),start)!=vis.end())
        return true;
        vis.push_back(start);
        for(int val:m[start]){
            if(val==parent){
                continue;
            }
            if(dfs(val,start,vis,m)){
               return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        map<int,vector<int>>m;
        vector<int> vis;
        for(int i=0;i<n;i++)
        {
            m[edges[i][0]].push_back(edges[i][1]);
            m[edges[i][1]].push_back(edges[i][0]);
            if(dfs(edges[i][0],-1,vis,m)){
                return {edges[i][0],edges[i][1]};
            }
            vis.clear();
        }
        return {};
    }
};