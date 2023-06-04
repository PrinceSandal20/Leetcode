class Solution {
public:
    void bfs(int start,vector<int> adj[],vector<int> &vis){
        vis[start]=1;
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        //unconnected components u can say also
        int n=isConnected.size(),m=isConnected[0].size();
        vector<int> adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n+1,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i]){
                ans++;
                bfs(i,adj,vis);
            }
        }
        return ans;
    }
};