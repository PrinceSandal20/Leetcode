class Solution {
public:
    bool squareIsWhite(string coordinates) {
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