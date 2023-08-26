class Solution {
    private:
    int find(int previdx,int idx,vector<vector<int>>&v,vector<vector<int>>&dp){
        if(idx>=v.size())return 0;
        if(dp[previdx+1][idx]!=-1)return dp[previdx+1][idx];
        int take=0;
        int not_take=find(previdx,idx+1,v,dp);
        if(previdx==-1 || v[previdx][1]<v[idx][0]){
            take=1+find(idx,idx+1,v,dp);
        }
        return dp[previdx+1][idx]=max(take,not_take);
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        vector<vector<int>>dp(pairs.size(),vector<int>(pairs.size(),-1));
        return find(-1,0,pairs,dp);
    }
};