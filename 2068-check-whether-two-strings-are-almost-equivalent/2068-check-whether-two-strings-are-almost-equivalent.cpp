class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int>map1(26,0),map2(26,0);
        for(auto val:word1){
            map1[val-'a']++;
        }
        for(auto val:word2){
            map2[val-'a']++;
        }
        for(int i=0;i<26;i++){
            if(abs(map1[i]-map2[i])>3){
                return false;
            }
        }
        return true;
    }
};