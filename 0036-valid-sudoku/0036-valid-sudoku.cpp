class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>>row(9),col(9),block(9);
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(row[i].count(board[i][j]-'0') || col[j].count(board[i][j]-'0') || block[(i/3*3+j/3)].count(board[i][j]-'0')){
                        return false;
                    }
                    row[i].insert(board[i][j]-'0');
                    col[j].insert(board[i][j]-'0');
                    block[(i/3*3+j/3)].insert(board[i][j]-'0');
                }
            }
        }
        return true;
    }
};