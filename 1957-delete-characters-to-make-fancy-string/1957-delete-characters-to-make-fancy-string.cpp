class Solution {
public:
    string makeFancyString(string s) {
        stack<pair<int,int>>st;
        for(int i=0;i<s.size();i++){
            if(!st.empty() && st.top().first==s[i]){
                st.push({s[i],st.top().second+1});
                if(st.top().second==3){
                    st.pop();
                }
            }
            else{
                st.push({s[i],1});
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};