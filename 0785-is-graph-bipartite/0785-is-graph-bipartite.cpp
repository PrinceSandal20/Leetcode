class Solution {
public:
    bool check(int start,vector<int>adj[],int color[]){
        queue<int>q;
        q.push(start);
        color[start]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto val:adj[node]){
                if(color[val]==-1){
                    color[val]=!color[node];
                    q.push(val);
                }
                else if(color[val]==color[node]){
                    return false;
                    break;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++)
        {
            for(auto val:graph[i]){
                adj[i].push_back(val);
                adj[val].push_back(i);
            }
        }
        int color[n];
        for(int i=0;i<n;i++) color[i]=-1;
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1){
                if(check(i,adj,color)==false){
                    return false;
                    break;
                }
            }
        }
        return true;
    }
};