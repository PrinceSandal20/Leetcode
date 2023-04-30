class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,int>row,col;
        unordered_map<int,pair<int,int>>m;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                m[mat[i][j]]={i,j};
            }
        }
        for(int i=0;i<arr.size();i++)
        {
            row[m[arr[i]].first]++;
            col[m[arr[i]].second]++;
            if(row[m[arr[i]].first]==mat[0].size() || col[m[arr[i]].second]==mat.size()){
                return i;
            }
        }
        return -1;
    }
};