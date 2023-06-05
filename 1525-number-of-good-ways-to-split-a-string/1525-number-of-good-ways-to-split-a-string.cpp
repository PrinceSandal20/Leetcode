class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int>m1,m2;
        for(int j=1;j<s.size();j++){
            m2[s[j]]++;
        }
        int i=0,j=1;
        int ans=0;
        while(i<s.size()-1 && j<s.size()){
            m1[s[i]]++;
            if(m1.size()==m2.size()){
                ans++;
            }
            m2[s[j]]--;
            if(m2[s[j]]==0)m2.erase(s[j]);
            i++,j++;
        }
        return ans;
    }
};