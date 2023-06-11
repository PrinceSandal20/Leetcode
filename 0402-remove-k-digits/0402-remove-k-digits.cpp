class Solution {
public:
    string removeKdigits(string s, int k) {
        if(s.size()<=k){
            return "0";
        }
        if(k==0){
            return s;
        }
        string ans="";
        stack<char>st;
        for(int i=0;i<s.size();i++){
            while(!st.empty() && k>0 &&  st.top()>s[i])
            {
               k--;
               st.pop();   
            }
            st.push(s[i]);
            if(st.size()==1 && s[i]=='0'){
                st.pop();
            }
        }
        while(k && !st.empty()){
            k--;
            st.pop();
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()==0){
            return "0";
        }
        else
          return ans;
    }
};