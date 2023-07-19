class Solution {
public:
    int calculate(string s) {
        long long sum=0;
        stack<pair<int,int>>st;
        int sign=1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='0' && s[i]<='9'){
                int test=0;
                while(i<s.size() && s[i]>='0' && s[i]<='9'){
                    test=test*10+(s[i]-'0');
                    i++;
                }
                i--;
                sum+=test*sign;
                sign=1;
            }
            else if(s[i]=='('){
                st.push({sum,sign});
                sum=0;
                sign=1;
            }
            else if(s[i]==')'){
                sum=st.top().first+(st.top().second*sum);
                st.pop();
            }
            else if(s[i]=='-'){
                sign=-1*sign;
            }
        }
        return sum;
    }
};