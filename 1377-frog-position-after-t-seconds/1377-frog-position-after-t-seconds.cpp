class Solution {
public:
    double ans=0.0;
    void dfs(int node,int target,vector<int>adj[],vector<int>&vis,int time,double prob){
        vis[node]=1;
        int siz=adj[node].size()-(node==1?0:1);
        if(node==target){
            if(time==0){
                ans=prob;
            }
            else if(time>0 && siz==0){
                ans=prob;
            }
            return ;
        }
        if(time>0){
            for(auto val:adj[node]){;
                if(!vis[val]){
                    dfs(val,target,adj,vis,time-1,prob/siz);
                }
            }
        }

    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<int>adj[n+1],vis(n+1,0);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        double prob=1.0;
        dfs(1,target,adj,vis,t,prob);
        return ans;
    }
};