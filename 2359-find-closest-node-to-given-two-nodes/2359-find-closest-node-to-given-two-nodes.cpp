class Solution {
public:
    void bfs(int node,vector<int>&dis,vector<int>&adj){
        queue<int>q;
        q.push(node);
        dis[node]=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            if(adj[u]!=-1){
                int v=adj[u];
                if(dis[v]>dis[u]+1){
                    dis[v]=dis[u]+1;
                    q.push(v);
                }
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int>dis1(n,1e9),dis2(n,1e9);
        bfs(node1,dis1,edges);
        bfs(node2,dis2,edges);
        int mxdist=1e9,node=-1;
        for(int i=0;i<n;i++){
            int cur_dis=max(dis1[i],dis2[i]);
            if(cur_dis<mxdist){
                mxdist=cur_dis;
                node=i;
            }
        }
        return node;
    }
};