class Solution {
public:
    void dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&ans){
        ans.push_back(node);
        vis[node]=1;
        for(auto val:adj[node]){
            if(!vis[val]){
                dfs(val,adj,vis,ans);
            }
        }
    }
    int bfs(int node,int n,vector<int>adj[]){
        queue<int>q;
        vector<int>vis(n+1,-1);
        q.push(node);
        vis[node]=1;
        int ans=1;
        while(!q.empty()){
            int val=q.front();
            q.pop();
            ans=max(ans,vis[val]);
            for(auto i:adj[val]){
                if(vis[i]!=-1 && abs(vis[i]-vis[val])!=1){
                    return -1;
                }
                if(vis[i]==-1){
                    vis[i]=vis[val]+1;
                    q.push(i);
                }
            }
        }
        return ans;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<int>adj[n+1],vis(n+1,0);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<vector<int>>compo;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                vector<int>res;
                dfs(i,adj,vis,res);
                compo.push_back(res);
            }
        }
        int ans=0;
        for(auto val:compo){
            int res=-1;
            for(auto node:val){
                res=max(res,bfs(node,n,adj));
            }
            if(res==-1){
                return -1;
            }
            ans+=res;
        }
        return ans;
    }
};