class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>&e, vector<int>& cost) {
        int n=cost.size();
        unordered_map<int,vector<pair<int,int>>>m;
        vector<int>time(n,maxTime+1);
        for(int i=0;i<e.size();i++){
            m[e[i][0]].push_back({e[i][1],e[i][2]});
            m[e[i][1]].push_back({e[i][0],e[i][2]});
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>minH;
        time[0]=0;
        minH.push({cost[0],{time[0],0}});
        while(!minH.empty()){
            int fee=minH.top().first;
            int t=minH.top().second.first;
            int node=minH.top().second.second;
            minH.pop();
            if(node==n-1){
                return fee;
            }
            for(auto val:m[node]){
                int u=val.first;
                int new_time=val.second;
                int new_cost=fee+cost[u];
                if(new_time+t<time[u]){
                    time[u]=new_time+t;
                    minH.push({new_cost,{new_time+t,u}});
                }
            }
        }
        return -1;
    }
};