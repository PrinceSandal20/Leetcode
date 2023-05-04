class Solution {
public:
    int dfs(int row,int col,int n,int m,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        if(row>n  || col>m){
            return INT_MAX;
        }
        if(row==n){
            return matrix[n][col];
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int ans=INT_MAX;
        for(int k=0;k<matrix.size();k++){
            if(k!=col){
                int sum=matrix[row][col]+dfs(row+1,k,n,m,matrix,dp);
                ans=min(ans,sum);
            }
        }
        return dp[row][col]=ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {
            ans=min(ans,dfs(0,i,n-1,n-1,matrix,dp));
        }
        return ans;
    }
};