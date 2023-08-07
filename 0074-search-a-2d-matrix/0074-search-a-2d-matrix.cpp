class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
         for(int i=0;i<n;i++){
              if(binary_search(matrix[i].begin(),matrix[i].end(),target)){
                    return true;
               }
          }
          return false;
    }
};