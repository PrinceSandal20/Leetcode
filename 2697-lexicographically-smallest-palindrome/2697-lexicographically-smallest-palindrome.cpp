class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int i=0,j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]){
                int s1=(int)s[i];
                int s2=(int)s[j];
                if(s1>s2){
                    s[i]=s[j];
                }
                else if(s2>s1){
                    s[j]=s[i];
                }
            }
            i++,j--;
        }
        return s;
    }
};