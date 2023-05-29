class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        unordered_map<char,int>m;
        int ans=-1,i=0,j=0;
        while(j<answerKey.size()){
            m[answerKey[j]]++;
            while(min(m['T'],m['F'])>k){
                m[answerKey[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};