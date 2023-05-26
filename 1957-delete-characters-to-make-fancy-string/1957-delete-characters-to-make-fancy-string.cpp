class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        ans+=s[0];
        for(int i=1;i<s.size();i++){
            if(s[i-1]==s[i] && s[i]==s[i+1]){
                continue;
            }
            ans+=s[i];
        }
        return ans;
    }
};