class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        vector<int>ans;
        bool dir=1;
        int i=0,j=0;
        while(i<row && j<col){
            if(dir==1){
                while(i>0 && j<col-1){
                    ans.push_back(mat[i][j]);
                    i--;
                    j++;
                }
                ans.push_back(mat[i][j]);
                if(j==col-1){
                    i++;
                }
                else{
                    j++;
                }
            }
            else{
                while(i<row-1 && j>0){
                    ans.push_back(mat[i][j]);
                    i++;
                    j--;
                }
                ans.push_back(mat[i][j]);
                if(i==row-1){
                    j++;
                }
                else{
                    i++;
                }
            }
            dir=!dir;
        }
        return ans;
    }
};