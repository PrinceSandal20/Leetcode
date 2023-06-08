class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int ans=0,sum=0;
        vector<int>v;
        unordered_set<int>st;
        for(auto val:banned){
            st.insert(val);
        }
        for(int i=1;i<=n;i++){
            if(st.find(i)==st.end() && sum+i<=maxSum){
                sum+=i;
                ans++;
            }
        }
        return ans;
    }
};