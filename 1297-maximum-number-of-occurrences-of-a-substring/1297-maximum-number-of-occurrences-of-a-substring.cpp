class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string,int>m2;
        unordered_map<char,int>m1;
        int i=0,j=0;
        int ans=0;
        string temp="";
        while(j<s.size()){
            temp.push_back(s[j]);
            m1[s[j]]++;
            while(temp.size()>minSize || m1.size()>maxLetters){
                temp.erase(temp.begin());
                m1[s[i]]--;
                if(m1[s[i]]==0)m1.erase(s[i]);
                i++;
            }
            if(temp.size()>=minSize && temp.size()<=maxSize && m1.size()<=maxLetters){
                m2[temp]++;
                ans=max(ans,m2[temp]);
            }
            j++;
        }
        return ans;
    }
};