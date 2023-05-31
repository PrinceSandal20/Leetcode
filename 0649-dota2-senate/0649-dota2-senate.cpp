class Solution {
public:
    string predictPartyVictory(string senate) {
     stack<char> st;
        for(int i = 0;i<senate.size();i++)
        {
            if(st.empty())
            {
                st.push(senate[i]);
            }
            else
            {
                if(st.top() != senate[i])
                {
                    char x = st.top();
                    st.pop();
                    senate += x;
                }
                else
                {
                    st.push(senate[i]);
                }
            }
        }
        string ans ="";
        if(st.top() == 'R')
        {
            ans = "Radiant";
        }
        else
        {
            ans = "Dire";
        }
        return ans;
    }
};