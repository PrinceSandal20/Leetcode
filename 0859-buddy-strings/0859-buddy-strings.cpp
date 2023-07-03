class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size() || s.size()<=1)return false;
        vector<int>test;
        if (s == goal) {
            unordered_set<char> distinctChars(s.begin(), s.end());
            return distinctChars.size() < s.length();
        }
        for(int i=0;i<s.size();i++){
            if(s[i]!=goal[i]){
                test.push_back(i);
            }
        }
        if(test.size()!=2)return false;
        swap(s[test[0]],s[test[1]]);
        return s==goal;
    }
};