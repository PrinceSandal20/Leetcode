class Solution {
public:
    vector<int>ans;
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&matrix,int n,int m){
        if(row<0 || row>n || col<0 || col>m || vis[row][col]==1){
            return;
        }
        if(!vis[row][col]){
            ans.push_back(matrix[row][col]);
            vis[row][col]=1;
        }
        if(row<=col+1){
            dfs(row,col+1,vis,matrix,n,m);
        }
        dfs(row+1,col,vis,matrix,n,m);
        dfs(row,col-1,vis,matrix,n,m);
        dfs(row-1,col,vis,matrix,n,m);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        dfs(0,0,vis,matrix,n-1,m-1);
        return ans;
    }
};