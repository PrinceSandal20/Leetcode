class Solution {
public:
    vector<int> pref(string s){
        int n=s.size();
        vector<int>lps(n,0);
        int i=1,j=0;
        while(i<n){
            if(s[i]==s[j]){
                lps[i]=j+1;
                i++,j++;
            }
            else{
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return lps;
    }
    int kmp(string txt,string pat){
        if(txt.size()<pat.size())return 0;
        vector<int>lps(pat.size());
        lps=pref(pat);
        vector<int>ans;
        int i=0,j=0;
        while(i<txt.size()){
            if(txt[i]==pat[j]){
                i++,j++;
            }
            else{
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
            if(j==pat.size()){
                return 1;
                //j=0;
            }
        }
        return 0;
    }
    int maxRepeating(string sequence, string word) {
       int ans=0;
       string s=word;
       while(kmp(sequence,s)>0){
           s+=word;
           ans++;
       }
       return ans;
    }
};