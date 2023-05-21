class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>st;
        unordered_set<int>t;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push({s[i],i});
            }
            else if(!st.empty() && st.top().first=='(' && s[i]==')'){
                t.insert(st.top().second);
                t.insert(i);
                st.pop();
            }
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            if(t.find(i)!=t.end()){
                ans+=s[i];
            }
            else if(s[i]>='a' && s[i]<='z'){
                ans+=s[i];
            }
        }
        return ans;
    }
};