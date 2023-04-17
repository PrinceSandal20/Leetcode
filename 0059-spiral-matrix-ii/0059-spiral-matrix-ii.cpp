class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&ans,int n,int m,int i){
        if(row<0 || row>n || col<0 || col>m || vis[row][col]==1){
            return;
        }
        if(!vis[row][col]){
            ans[row][col]=i;
            i++;
            vis[row][col]=1;
        }
        if(row<=col+1){
            dfs(row,col+1,vis,ans,n,m,i);
        }
        dfs(row+1,col,vis,ans,n,m,i);
        dfs(row,col-1,vis,ans,n,m,i);
        dfs(row-1,col,vis,ans,n,m,i);
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vis(n,vector<int>(n,0));
        vector<vector<int>>ans(n,vector<int>(n,0));
        dfs(0,0,vis,ans,n-1,n-1,1);
        return ans;
    }
};