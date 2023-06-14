class Solution {
public:
    string removeDuplicateLetters(string s) {
       string ans="";
        vector<int>vis(26,0),map(26,0);
        for(int i=0;i<s.size();i++){
            map[s[i]-'a']++;
        }
        stack<char>st;
        for(int i=0;i<s.size();i++){
            map[s[i]-'a']--;
            if(!vis[s[i]-'a']){
                while(!st.empty() && st.top()>s[i] && map[st.top()-'a']!=0){
                    vis[st.top()-'a']=0;
                    st.pop();
                }
                st.push(s[i]);
                vis[st.top()-'a']=1;
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};