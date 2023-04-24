class Solution {
public:
    bool dfs(int row,int col,int n,int m,vector<vector<char>>& board,string word,int idx){
        if(idx==word.size()){
            return true;
        }
        if(row<0 || col<0 || row>n || col>m || board[row][col]!=word[idx]){
            return false;
        }
        char ch=board[row][col];
        board[row][col]='0';
        bool a=dfs(row,col+1,n,m,board,word,idx+1);
        bool b=dfs(row+1,col,n,m,board,word,idx+1);
        bool c=dfs(row,col-1,n,m,board,word,idx+1);
        bool d=dfs(row-1,col,n,m,board,word,idx+1);
        board[row][col]=ch;
        return a || b || c || d;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(i,j,n-1,m-1,board,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
};