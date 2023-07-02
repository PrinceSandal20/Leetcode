class Solution {
    private:
      void backtrack(string temp,int n,int k,vector<char>&ch,vector<string>&ans){
          if(ans.size()==k){
              return;
          }
          if(temp.size()==n){
              ans.push_back(temp);
              return;
          }
          for(int i=0;i<3;i++){
              if(temp.size()==0 || temp[temp.size()-1]!=ch[i]){
                    temp.push_back(ch[i]);
                    backtrack(temp,n,k,ch,ans);
                    temp.pop_back();
              }
          }
      }
public:
    string getHappyString(int n, int k) {
        vector<char>ch={'a','b','c'};
        vector<string>ans;
        backtrack("",n,k,ch,ans);
        return ans.size()!=k?"":ans.back();
    }
};