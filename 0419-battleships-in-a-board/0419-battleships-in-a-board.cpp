class Solution {
public:
    void dfs(int row,int col,int n,int m,vector<vector<int>>&vis,vector<vector<char>>&board){
        if(row<0 || col<0 || row>n || col>m || vis[row][col]==1 || board[row][col]=='.'){
            return;
        }
        vis[row][col]=1;
        dfs(row+1,col,n,m,vis,board);
        dfs(row-1,col,n,m,vis,board);
        dfs(row,col+1,n,m,vis,board);
        dfs(row,col-1,n,m,vis,board);
    }
    int countBattleships(vector<vector<char>>& board) {
        int ans=0;
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='X' && !vis[i][j]){
                    dfs(i,j,n-1,m-1,vis,board);
                    ans++;
                }
            }
        }
        return ans;
    }
};