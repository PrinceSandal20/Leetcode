class Solution {
public:
    bool isPalindrome(string s,int i,int j){
        if(i>=j){
            return true;
        }
        if(s[i]==s[j]){
            return isPalindrome(s,i+1,j-1);
        }
        else
           return false;
    }
    int maxPalindromes(string s, int k) {
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j<s.size();j++)
            {
                if(j-i+1>k+1){
                    break;
                }
                if(isPalindrome(s,i,j) && j-i+1>=k)
                {
                    ans++;
                    i=j;
                    break;
                }
            }
        }
        return ans;
    }
};