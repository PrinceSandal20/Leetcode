class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long siz=0;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                siz*=s[i]-'0';
            }
            else{
                siz++;
            }
        }
        for(int i=s.size()-1;i>=0;i--){
            k%=siz;
            if(k==0 && isalpha(s[i])){
                string ans="";
                ans+=s[i];
                return ans;
            }
            if(isdigit(s[i])){
                siz/=s[i]-'0';
            }
            else{
                siz--;
            }
        }
        return " ";
    }
};