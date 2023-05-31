class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        unordered_map<int,vector<pair<int,int>>>m;
        for(int i=0;i<redEdges.size();i++){
            m[redEdges[i][0]].push_back({redEdges[i][1],0});
        }
        for(int i=0;i<blueEdges.size();i++){
            m[blueEdges[i][0]].push_back({blueEdges[i][1],1});
        }
        vector<int>ans(n,-1);
        vector<vector<int>>vis(n,vector<int>(2));
        queue<vector<int>>q;
        q.push({0,0,-1});
        vis[0][0]=vis[0][1]=1;
        ans[0]=0;
        while(!q.empty()){
            int node=q.front()[0];
            int step=q.front()[1];
            int prevcolor=q.front()[2];
            q.pop();
            for(auto val:m[node]){
                int nd=val.first;
                int color=val.second;
                if(!vis[nd][color] && color!=prevcolor){
                    vis[nd][color]=1;
                    q.push({nd,step+1,color});
                    if(ans[nd]==-1){
                        ans[nd]=step+1;
                    }
                }
            }
        }
        return ans;
    }
};