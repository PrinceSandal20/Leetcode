class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        vector<int>lps(n,0);
        int i=1,j=0;
        while(i<n){
            if(s[i]==s[j]){
                lps[i]=j+1;
                i++,j++;
            }
            else{
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        if(lps[n-1]!=0 && lps[n-1]%(n-lps[n-1])==0){
            return true;
        }
        return false;
    }
};