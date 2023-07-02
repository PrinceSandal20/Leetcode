class Solution {
public:
    long long dividePlayers(vector<int>& skills) {
        if(skills.size()%2)return -1;
        sort(skills.begin(),skills.end());
        int i=0,j=skills.size()-1;
        long long ans=0;
        unordered_set<int>st;
        while(i<=j){
            ans+=skills[i]*skills[j];
            st.insert(skills[i]+skills[j]);
            i++,j--;
        }
        if(st.size()>1)return -1;
        return ans;
    }
};