class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long ans=0;
        vector<pair<int,int>>vis(n,{0,0});
        int r=0,c=0;
        for(int i=queries.size()-1;i>=0;i--){
            int type=queries[i][0];
            int val=queries[i][2];
            if(type==0){
                int idx=queries[i][1];
                if(vis[idx].first==0){
                    ans+=val*(n-c);
                    r++;
                    vis[idx].first=1;
                }
            }
            else{
                int idx=queries[i][1];
                if(vis[idx].second==0){
                    ans+=val*(n-r);
                    c++;
                    vis[idx].second=1;
                }
            }
        }
        return ans;
    }
};