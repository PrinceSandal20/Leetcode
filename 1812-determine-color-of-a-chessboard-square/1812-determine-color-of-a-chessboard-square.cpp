class Solution {
public:
    bool squareIsWhite(string coordinates) {
        vector<vector<int>>board(8,vector<int>(8,0));
        int flag=1;
        for(int i=7;i>=0;i--){
            if(flag==0){
                for(int j=0;j<8;j++){
                  if(j%2==0){
                      board[i][j]=0;
                  }
                  else{
                      board[i][j]=1;
                  }
                }  
                flag=1;
            }
            else{
                for(int j=0;j<8;j++){
                  if(j%2==0){
                      board[i][j]=1;
                  }
                  else{
                      board[i][j]=0;
                  }
                }  
                flag=0;
            }
        }
        int col=coordinates[0]-'a' ,row=coordinates[1]-1;
        if(col%2==0){
            if(row%2==0){
                return false;
            }
            else{
                return true;
            }
        }
        else{
            if(row%2==0){
                return true;
            }
            else{
                return false;
            }
        }
        return false;
    }
};