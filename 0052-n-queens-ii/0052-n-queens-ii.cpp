class Solution {
public:
    bool valid(int row,int col,vector<vector<char>>&vis){
        int x=row;
        int y=col;
        while(row>=0 && col>=0){
            if(vis[row][col]=='Q'){
                return false;
            }
            col--;
            row--;
        }
        row=x;
        col=y;
        while(col>=0){
            if(vis[row][col]=='Q'){
                return false;
            }
            col--;
        }
        row=x;
        col=y;
        while(col>=0 && row<vis.size()){
            if(vis[row][col]=='Q'){
                return false;
            }
            row++;
            col--;
        }
        return true;
    }
    vector<string> construct(vector<vector<char>>&vis){
        vector<string>res;
        for(int i=0;i<vis.size();i++){
            string s="";
            for(int j=0;j<vis.size();j++){
                s+=vis[i][j];
            }
            res.push_back(s);
        }
        return res;
    }
    void dfs(int col,int n, vector<vector<char>>&vis,vector<vector<string>>&ans){
        if(col==n){
            ans.push_back(construct(vis));
            return ;
        }
        for(int row=0;row<n;row++){
            if(valid(row,col,vis)){
                vis[row][col]='Q';
                dfs(col+1,n,vis,ans);
                vis[row][col]='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<char>>vis(n,vector<char>(n,'.'));
        vector<vector<string>>ans;
        dfs(0,n,vis,ans);
        return ans.size();
    }
};