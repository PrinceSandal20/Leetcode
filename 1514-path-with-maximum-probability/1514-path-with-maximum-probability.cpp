class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        map<int,vector<pair<int,double>>>mp;
        for(int i=0;i<edges.size();i++){
            mp[edges[i][0]].push_back({edges[i][1],succProb[i]});
            mp[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double>prob(n,0.0);
        prob[start]=1.0;
        queue<int>q;
        q.push(start);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto val:mp[node]){
                int newnode=val.first;
                double res=val.second;
                if(prob[newnode]<res*prob[node]){
                    prob[newnode]=res*prob[node];
                    q.push(newnode);
                }
            }
        }
        return prob[end];
    }
};