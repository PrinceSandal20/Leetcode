class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        st.push({s[0],1});
        for(int i=1;i<s.size();i++){
            if(!st.empty() && st.top().first==s[i]){
                st.push({s[i],st.top().second+1});
                if(st.top().second==k){
                    int cnt=k;
                    while(!st.empty() && cnt>0){
                        cnt--;
                        st.pop();
                    }
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