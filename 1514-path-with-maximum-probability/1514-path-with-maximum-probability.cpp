class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        map<int,vector<pair<int,double>>>mp;
        for(int i=0;i<edges.size();i++){
            mp[edges[i][0]].push_back({edges[i][1],succProb[i]});
            mp[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double>prob(n,0.0);
        priority_queue<pair<double,int>>q;
        q.push({1.0,start});
        prob[start]=1.0;
        while(!q.empty()){
            double p=q.top().first;
            int node=q.top().second;
            q.pop();
            for(auto val:mp[node]){
                int newnode=val.first;
                double res=val.second;
                if(prob[newnode]<res*p){
                    prob[newnode]=res*p;
                    q.push({prob[newnode],newnode});
                }
            }
        }
        return prob[end];
    }
};