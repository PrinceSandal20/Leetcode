class Solution {
public:
    void findans(string ds,string s,vector<string>&ans,int freq[],int k,int &count){
      if (ds.size() == s.size()) {
        ans.push_back(ds);
        count++;
        if(count==k){
          return;
        }
      }
      for (int i = 0; i < s.size(); i++) {
        if (!freq[i]) {
          ds.push_back(s[i]);
          freq[i] = 1;
          findans(ds,s,ans, freq,k,count);
          freq[i] = 0;
          ds.pop_back();
        }
        if(count==k){
          return ;
        }
      }
    }
    string getPermutation(int n, int k) {
      string s="";
      for(int i=1;i<=n;i++){
          s+=to_string(i);
      }
      vector<string>ans;
      int freq[s.size()];
      for (int i=0;i<s.size();i++) freq[i]=0;
      int count=0;
      findans("",s,ans,freq,k,count);
      return ans[k-1];
    }
};