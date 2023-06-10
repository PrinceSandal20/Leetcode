class Solution {
public:
    bool isPalindrome(string &s,int i,int j){
        if(i>=j)return true;
        while(i <j)
        {
            if(s[i]!= s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int find(string &s,int i,int j,vector<int>&dp){
        if(i>=j || isPalindrome(s,i,j)){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=INT_MAX;
        for(int idx=i;idx<j;idx++){
            if(isPalindrome(s,i,idx)){
                int cuts=1+find(s,idx+1,j,dp);
                ans=min(ans,cuts);
            }
        }
        return dp[i]=ans;
    }
    int minCut(string s) {
        vector<int>dp(s.size()+1,-1);
        return find(s,0,s.size()-1,dp);
    }
};