class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int mx=INT_MIN;
        int pos;
        for(int i=0;i<mat.size();i++){
            int one=0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1){
                    one++;
                }
            }
            if(mx<one){
                mx=one;
                pos=i;
            }
        }
        return {pos,mx};
    }
};