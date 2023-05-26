class Solution {
public:
    int ans(int idx,vector<int>&score,vector<string>&words,unordered_map<char,int>m,string ds){
        if(idx>=words.size()){
            int res=0;
           // cout<<ds<<endl;
            for(int i=0;i<ds.size();i++){
                if(m[ds[i]]==0){
                    return 0;
                }
                else{
                    m[ds[i]]--;
                    res+=score[ds[i]-'a'];
                }
            }
            return res;
        }
        int take=0,not_take=0;
        take=ans(idx+1,score,words,m,ds+words[idx]);
        not_take=ans(idx+1,score,words,m,ds);
        return max(take,not_take);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,int>m;
        for(int i=0;i<letters.size();i++){
            m[letters[i]]++;
        }
        return ans(0,score,words,m,"");
    }
};