class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string test="";
        for(int i=0;i<words.size();i++){
            test.push_back(words[i][0]);
        }
        return test==s;
    }
};