class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int>adj[n];
        for(int i=0;i<manager.size();i++)
        {
            if(manager[i]!=-1){
                adj[manager[i]].push_back(i);
            }
        }
        int ans=0;
        queue<pair<int,int>>q;
        q.push({headID,informTime[headID]});
        while(!q.empty()){
            int node=q.front().first;
            int time=q.front().second;
            q.pop();
            for(auto val:adj[node]){
                ans=max(ans,time+informTime[val]);
                q.push({val,time+informTime[val]});
            }
        }
        return ans;
    }
};