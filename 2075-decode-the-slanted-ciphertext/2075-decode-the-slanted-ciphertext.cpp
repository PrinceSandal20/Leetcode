class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n=encodedText.size(),cols=n/rows;
        vector<vector<char>>grid(rows,vector<char>(cols));
        int j=0,k=0;
        for(int i=0;i<encodedText.size();i++){
            grid[j][k]=encodedText[i];
            if(k==cols-1){
                k=0;
                j++;
            }
            else{
                k++;
            }
        }
        string ans="";
        int i=0,count=0;
        j=0;
        while(i<rows && j<cols){
            ans+=grid[i][j];
            i++,j++;
            if(i==rows || j==cols){
                i=0;
                count++;
                j=count;
            }
        }
        while(ans.back()==' ')ans.pop_back();
        return ans;
    }
};