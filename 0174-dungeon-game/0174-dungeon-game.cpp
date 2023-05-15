class Solution {
public:
    int dfs(int row,int col,int n,int m,vector<vector<int>>&dungeon,vector<vector<int>>&dp){
        if(row>n || col>m){
            return 1e9;
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        if(row==n && col==m){
            if(dungeon[row][col]<=0){
                return 1-dungeon[row][col];
            }
            else{
                return 1;
            }
        }
        int side=dfs(row,col+1,n,m,dungeon,dp);
        int down=dfs(row+1,col,n,m,dungeon,dp);
        int health=min(side,down)-dungeon[row][col];
        //cout<<side<<"->"<<down<<"->"<<health<<"->"<<row<<"->"<<col<<endl;
        return dp[row][col]=health<=0?1:health;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return dfs(0,0,n-1,m-1,dungeon,dp);
    }
};