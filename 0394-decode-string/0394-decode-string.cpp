class Solution {
public:
    string decodeString(string s) {
        string ans="";
        stack<int>num;
        stack<string>st;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                int n=0;
                while(isdigit(s[i])){
                    n=n*10+(s[i]-'0');
                    i++;
                }
                i--;
                num.push(n);
                n=0;
            }
            else if(s[i]=='['){
                st.push(ans);
                ans="";
            }
            else if(s[i]==']'){
                string x="";
                x+=st.top();
                st.pop();
                int number=num.top();
                num.pop();
                for(int k=0;k<number;k++){
                    x+=ans;
                }
                ans=x;
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};