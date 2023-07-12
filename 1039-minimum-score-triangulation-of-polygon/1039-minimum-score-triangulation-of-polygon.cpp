class Solution {
    private:
    int findans(int i,int j,vector<int>&arr,vector<vector<int>>&dp){
        if(i>=j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            int cost=arr[i-1]*arr[k]*arr[j]+findans(i,k,arr,dp)+findans(k+1,j,arr,dp);
            ans=min(ans,cost);
        }
        return dp[i][j]=ans;
    }
public:
    int minScoreTriangulation(vector<int>&arr) {
        int N=arr.size();
        vector<vector<int>>dp(N,vector<int>(N,-1));
       return findans(1,N-1,arr,dp);
    }
};