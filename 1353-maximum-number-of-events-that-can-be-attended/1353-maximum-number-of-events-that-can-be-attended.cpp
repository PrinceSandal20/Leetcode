class Solution
{
public:
    int maxEvents(vector<vector<int>> &events)
    {
        int ans=0;
        sort(events.begin(),events.end(),[](auto const &a, auto const &b){return a[1]<b[1];});
        int mx=events[events.size()-1][1];
        set<int>st;
        for(int i=1;i<=mx;i++)
        {
            st.insert(i);
        }
        for(int i=0;i<events.size();i++)
        {
            int start=events[i][0],end=events[i][1];
            auto it=st.lower_bound(start);
            if(it==st.end() || *it>end){
                continue;
            }
            else{
                ans++;
                st.erase(it);
            }
        }
        return ans;
    }
};