class Solution {
    private:
    int dp[101][27];
    int find(int idx,int num,string &s){
        if(idx==s.size()){
            if(num%25==0){
                return 0;
            }
            return 1e9;
        }
        if(dp[idx][num]!=-1){
            return dp[idx][num];
        }
        int digit=s[idx]-'0';
        int take=1+find(idx+1,num,s);
        int not_take=find(idx+1,(num*10+digit)%25,s);
        return dp[idx][num]=min(take,not_take);
    }
public:
    int minimumOperations(string num) {
        memset(dp,-1,sizeof(dp));
        return find(0,0,num);
    }
};