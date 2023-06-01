class Solution {
public:
    int dfs(long long int n,unordered_map<long long int,long long int>&dp){
        if(n==1){
            return 0;
        }
        if(dp.count(n)>0){
            return dp[n];
        }
        int a=INT_MAX,b=INT_MAX,c=INT_MAX;
        if(n%2==0){
            a=1+dfs(n>>1,dp);
        }
        else{
            b=1+dfs(n+1,dp);
            c=1+dfs(n-1,dp);
        }
        return dp[n]=min({a,b,c});
    }
    int integerReplacement(int n) {
        unordered_map<long long int,long long int>dp;
        return dfs(n,dp);
    }
};