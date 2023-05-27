class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>degree(n,0);
        unordered_map<int,unordered_set<int>>m;
        for(int i=0;i<roads.size();i++)
        {
            m[roads[i][0]].insert(roads[i][1]);
            m[roads[i][1]].insert(roads[i][0]);
            degree[roads[i][0]]++;
            degree[roads[i][1]]++;
        }
        int rank=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(m[i].find(j)!=m[i].end() &&  m[j].find(i)!=m[j].end()){
                    rank=max(rank,degree[i]+degree[j]-1);
                }
                else{
                    rank=max(rank,degree[i]+degree[j]);
                }
            }
        }
        return rank;
    }
};