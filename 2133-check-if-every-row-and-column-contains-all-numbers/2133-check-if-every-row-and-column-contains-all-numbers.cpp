class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int ans1=0,ans2=0;
        for(int i=0;i<matrix.size();i++)
        {
            unordered_map<int,int>row;
            for(int j=0;j<matrix[0].size();j++)
            {
                row[matrix[i][j]]++;
            }
            if(row.size()==matrix.size()){
                ans1++;
            }
        }
        for(int j=0;j<matrix[0].size();j++)
        {
            unordered_map<int,int>col;
            for(int i=0;i<matrix.size();i++)
            {
                col[matrix[i][j]]++;
            }
            if(col.size()==matrix[0].size()){
                ans2++;
            }
        }
        if(ans1+ans2==2*matrix.size()){
            return true;
        }
        return false;
    }
};