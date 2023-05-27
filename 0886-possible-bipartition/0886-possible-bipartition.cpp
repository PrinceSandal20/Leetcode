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
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>adj[n+1];
        for(int i=0;i<dislikes.size();i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        int color[n+1];
        for(int i=1;i<=n;i++) color[i]=-1;
        for(int i=1;i<=n;i++)
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