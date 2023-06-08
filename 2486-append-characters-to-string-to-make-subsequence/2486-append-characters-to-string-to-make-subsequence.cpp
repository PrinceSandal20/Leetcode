class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0,j=0;
        int ans=0;
        while(i<s.size() && j<t.size()){
            if(t[j]==s[i]){
                ans++;
                i++,j++;
            }
            else if(t[j]!=s[i]){
                i++;
            }
        }
        return t.size()-ans;
    }
};