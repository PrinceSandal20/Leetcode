class Solution {
public:
    vector<int> getRow(int row) {
        long long ans=1;
        vector<int>temp;
        temp.push_back(1);
        row=row+1;
        for(int col=1;col<row;col++){
            ans=ans*(row-col);
            ans=ans/col;
            temp.push_back(ans);
        }
        return temp;
    }
};