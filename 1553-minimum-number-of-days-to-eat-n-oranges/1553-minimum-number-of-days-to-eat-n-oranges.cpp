class Solution {
public:
    unordered_map<int,int>dp;
    int minDays(int n) {
        if(n<=1){
            return n;
        }
        if(dp.count(n)>0){
            return dp[n];
        }
        return dp[n]=1+min((n%2)+minDays(n/2),(n%3)+minDays(n/3));
    }
};