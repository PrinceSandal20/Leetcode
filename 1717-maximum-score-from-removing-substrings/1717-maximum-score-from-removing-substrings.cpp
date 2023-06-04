class Solution {
public:
    int find(string &s,char a,char b){
        int ans=0;
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(!st.empty() && st.top()==a && s[i]==b){
                st.pop();
                ans++;
            }
            else{
                st.push(s[i]);
            }
        }
        s="";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return ans;
    }
    int maximumGain(string s, int x, int y) {
        int count_ab=0,count_ba=0;
        if(x>y){
            count_ab=find(s,'a','b');
            count_ba=find(s,'b','a');
        }
        else{
            count_ba=find(s,'b','a');
            count_ab=find(s,'a','b');
        }
        return count_ab*x+count_ba*y;
    }
};