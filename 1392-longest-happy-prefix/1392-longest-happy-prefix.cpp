class Solution {
public:
    string longestPrefix(string s) {
        vector<int>lps(s.size(),0);
        int i=1,j=0;
        while(i<s.size()){
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
        return s.substr(0,lps[s.size()-1]);
    }
};