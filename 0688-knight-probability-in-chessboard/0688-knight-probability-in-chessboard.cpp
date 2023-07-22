class Solution {
    private:
    vector<pair<int,int>>dir={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
    unordered_map<string,double>memo;
public:
    double knightProbability(int n, int k, int row, int column) {
        if(row<0 || column<0 || row>=n || column>=n)return 0;
        if(k==0)return 1;
        string s=to_string(row)+" "+to_string(column)+" "+to_string(k);
        if(memo.find(s)!=memo.end())return memo[s];
        double prob=0;
        for(int i=0;i<8;i++){
            prob+=knightProbability(n,k-1,row+dir[i].first,column+dir[i].second)/8.0;
        }
        return memo[s]=prob;
    }
};