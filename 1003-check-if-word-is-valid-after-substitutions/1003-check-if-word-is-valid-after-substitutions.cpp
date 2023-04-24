class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(!st.empty() && st.top()=='b' && s[i]=='c'){
                 char ch=st.top();
                 st.pop();
                 if(!st.empty() && st.top()=='a'){
                     st.pop();
                 }
                 else{
                     st.push(ch);
                 }
            }
            else{
                st.push(s[i]);
            }
        }
        return st.size()==0;
    }
};