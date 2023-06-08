class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int ans=0;
        int row=startPos[0],col=startPos[1];
        int home1=homePos[0],home2=homePos[1];
        while(row<home1){
            row++;
            ans+=rowCosts[row];
        }
        while(col<home2){
            col++;
            ans+=colCosts[col];
        }
        while(row>home1){
            row--;
            ans+=rowCosts[row];
        }
        while(col>home2){
            col--;
            ans+=colCosts[col];
        }
        return ans;
    }
};