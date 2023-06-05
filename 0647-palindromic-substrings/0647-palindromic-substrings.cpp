class Solution {
public:
    int ispalindrome(string &s,int i,int j){
        if(i>=j){
            return 1;
        }
        if(s[i]==s[j]){
            return ispalindrome(s,i+1,j-1);
        }
        else
            return 0;
    }
    int countSubstrings(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(ispalindrome(s,i,j)){
                    ans++;
                }
            }
        }
        return ans;
    }
};