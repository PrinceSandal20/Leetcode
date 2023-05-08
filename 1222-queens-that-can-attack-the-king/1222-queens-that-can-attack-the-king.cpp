class Solution {
public:
    void dfs(int row,int col,int n,int m,vector<vector<int>>&ans,int dir){
        if(row<0 || col<0 || row>n || col>m){
            return ;
        }
        if(dir==1){
            if(ans[row][col]==2){
                ans[row][col]=3;
                return;
            }
            dfs(row+1,col,ans.size()-1,ans[0].size()-1,ans,1);
        }
        else if(dir==2){
            if(ans[row][col]==2){
                ans[row][col]=3;
                return;
            }
            dfs(row-1,col,ans.size()-1,ans[0].size()-1,ans,2);
        }
        else if(dir==3){
            if(ans[row][col]==2){
                ans[row][col]=3;
                return;
            }
             dfs(row,col+1,ans.size()-1,ans[0].size()-1,ans,3);
        }
        else if(dir==4){
            if(ans[row][col]==2){
                ans[row][col]=3;
                return;
            }
            dfs(row,col-1,ans.size()-1,ans[0].size()-1,ans,4);
        }
        else if(dir==5){
            if(ans[row][col]==2){
                ans[row][col]=3;
                return;
            }
            dfs(row+1,col+1,ans.size()-1,ans[0].size()-1,ans,5);
        }
        else if(dir==6){
            if(ans[row][col]==2){
                ans[row][col]=3;
                return;
            }
            dfs(row-1,col-1,ans.size()-1,ans[0].size()-1,ans,6);
        }
        else if(dir==7){
            if(ans[row][col]==2){
                ans[row][col]=3;
                return;
            }
            dfs(row+1,col-1,ans.size()-1,ans[0].size()-1,ans,7);
        }
        else if(dir==8){
            if(ans[row][col]==2){
                ans[row][col]=3;
                return;
            }
            dfs(row-1,col+1,ans.size()-1,ans[0].size()-1,ans,8);
        }
    }
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>>ans(8,vector<int>(8,0));
        ans[king[0]][king[1]]=1;
        for(int i=0;i<queens.size();i++){
            ans[queens[i][0]][queens[i][1]]=2;
        }
        int row=king[0],col=king[1];
        dfs(row+1,col,ans.size()-1,ans[0].size()-1,ans,1);
        dfs(row-1,col,ans.size()-1,ans[0].size()-1,ans,2);
        dfs(row,col+1,ans.size()-1,ans[0].size()-1,ans,3);
        dfs(row,col-1,ans.size()-1,ans[0].size()-1,ans,4);
        dfs(row+1,col+1,ans.size()-1,ans[0].size()-1,ans,5);
        dfs(row-1,col-1,ans.size()-1,ans[0].size()-1,ans,6);
        dfs(row+1,col-1,ans.size()-1,ans[0].size()-1,ans,7);
        dfs(row-1,col+1,ans.size()-1,ans[0].size()-1,ans,8);
        vector<vector<int>>res;
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[0].size();j++){
                if(ans[i][j]==3){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};