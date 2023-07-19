class Solution {
public:
    int dfs(int idx,int siz,int sum,string &s,vector<vector<int>>&dp){
        if(idx<0){
            return 0;
        }
        if(dp[idx][siz]!=-1)return dp[idx][siz];
        int take=0;
        int not_take=dfs(idx-1,siz,sum,s,dp);
        if((sum-(s[idx]-'0')*pow(2,siz))>=0){
            take=1+dfs(idx-1,siz+1,(sum-(s[idx]-'0')*pow(2,siz)),s,dp);
        }
        return dp[idx][siz]=max(take,not_take);
    }
    int longestSubsequence(string s, int k) {
        //work backwards
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return dfs(n-1,0,k,s,dp);
    }
};