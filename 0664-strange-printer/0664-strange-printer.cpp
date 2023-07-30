class Solution {
    private:
    int find(int i,int j,string &s,vector<vector<int>>&dp){
        if(i==j)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int minturns=INT_MAX;
        for(int k=i;k<j;k++){
            minturns=min(minturns,find(i,k,s,dp)+find(k+1,j,s,dp));
        }
        return dp[i][j]=(s[i]==s[j]?minturns-1:minturns);
    }
public:
    int strangePrinter(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return find(0,n-1,s,dp);
    }
};