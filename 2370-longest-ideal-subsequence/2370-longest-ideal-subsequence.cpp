class Solution {
public:
    int n;
    int find(int idx,int previdx,string &s,vector<vector<int>>&dp,int &k){
        if(idx>=n){
            return 0;
        }
        if(dp[idx][previdx]!=-1){
            return dp[idx][previdx];
        }
        int take=0;
        int not_take=0+find(idx+1,previdx,s,dp,k);
        if(previdx==0 || abs(s[idx]-'a'+1-previdx)<=k){
            take=1+find(idx+1,s[idx]-'a'+1,s,dp,k);
        }
        return dp[idx][previdx]=max(take,not_take);
    }
    int longestIdealString(string s, int k) {
        n=s.size();
        vector<vector<int>>dp(n,vector<int>(27,-1));
        return find(0,0,s,dp,k);
    }
};