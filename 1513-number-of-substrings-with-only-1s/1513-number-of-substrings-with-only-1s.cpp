class Solution {
public:
    int numSub(string s) {
        long long res=0,mode=1e9+7;
        long long i=0,j=0;
        while(j<s.size()){
            if(s[i]=='1' && s[j]=='1'){
                while(j<s.size() && s[j]=='1'){
                    j++;
                }
                j--;
                res+=(long long)(j-i+1)*(j-i+1+1)/2;
                j++;
                i=j;
            }
            i++,j++;
        }
        return res%mode;
    }
};