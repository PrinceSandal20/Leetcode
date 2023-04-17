class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++)
            {
                if(i==j){
                    ans+=mat[i][j];
                }
            }
        }
        cout<<ans<<"fuk"<<endl;
        for(int i=0;i<mat.size();i++){
            for(int j=mat[0].size()-1;j>=0;j--){
                ans+=mat[i][j];
                i++;
            }
        }
        if(mat.size()%2!=0){
            int n=mat.size();
            int m=mat[0].size();
            return ans-mat[n/2][m/2];
        }
        return ans;
    }
};