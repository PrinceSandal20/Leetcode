class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
      unordered_map<string,int>m;
      for(auto &val:paragraph){
            val=isalpha(val)?tolower(val):' '; 
      }
      istringstream iss(paragraph);
      string temp;
      while(iss>>temp){
          m[temp]++;
      }
      for(auto val:banned){
          m[val]=0;
      }
      int mx=-1;
      string ans="";
      for(auto val:m){
          if(mx<val.second){
              mx=val.second;
              ans=val.first;
          }
      }
      return ans;
    }
};