class Solution {
    void findans(int idx,int n,vector<vector<int>> &ans,vector<int> &ds,int k){
        if(ds.size()>k) return;
        if (ds.size()==k) {
          ans.push_back(ds);
            return ;
        }
        for(int i=idx; i<=n; i++){
            ds.push_back(i);
            findans(i+1,n,ans,ds,k);
            ds.pop_back();
        }
      }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> res;
        findans(1,n,ans,res,k);
        return ans;
    }
};