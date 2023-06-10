class Solution {
public:
    bool isPalindrome(string s,int i,int j){
        if(i>=j){
            return true;
        }
        if(s[i]==s[j]){
            return isPalindrome(s,i+1,j-1);
        }
        else
           return false;
    }
    void find(int idx,vector<string>&ds,vector<vector<string>>&ans,string &s){
        if(idx==s.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(isPalindrome(s,idx,i)){
                ds.push_back(s.substr(idx,i-idx+1));
                find(i+1,ds,ans,s);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>ds;
        find(0,ds,ans,s);
        return ans;
    }
};