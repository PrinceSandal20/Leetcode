class Solution {
public:
    int dfs(int row,int col,int n,int m,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int a=0,b=0,c=0,d=0;
        if(row+1<=n && matrix[row][col]<matrix[row+1][col]){
            a=dfs(row+1,col,n,m,matrix,dp);
        }
        if(row-1>=0 && matrix[row][col]<matrix[row-1][col]){
            b=dfs(row-1,col,n,m,matrix,dp);
        }
        if(col+1<=m && matrix[row][col]<matrix[row][col+1]){
            c=dfs(row,col+1,n,m,matrix,dp);
        }
        if(col-1>=0 && matrix[row][col]<matrix[row][col-1]){
            d=dfs(row,col-1,n,m,matrix,dp);
        }
        return dp[row][col]=max(a,max(b,max(c,d)))+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]==-1){
                    ans=max(ans,dfs(i,j,n-1,m-1,matrix,dp));
                }
            }
        }
        return ans;
    }
};