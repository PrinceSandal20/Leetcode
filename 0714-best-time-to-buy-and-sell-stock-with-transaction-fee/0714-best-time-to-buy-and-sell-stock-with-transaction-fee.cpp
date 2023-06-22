class Solution {
public:
    int find(int idx,int buy,int fee,vector<int>&prices,vector<vector<int>>&dp){
        if(idx==prices.size())return 0;
        if(dp[idx][buy]!=-1){
            return dp[idx][buy];
        }
        int profit=0;
        if(buy){
            int not_buy=find(idx+1,1,fee,prices,dp);
            int buy=-prices[idx]+find(idx+1,0,fee,prices,dp);
            profit=max(buy,not_buy);
        }
        else{
            int sell=prices[idx]-fee+find(idx+1,1,fee,prices,dp);
            int not_sell=find(idx+1,0,fee,prices,dp);
            profit=max(sell,not_sell);
        }
        return dp[idx][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return find(0,1,fee,prices,dp);
    }
};