class Solution {
private:
    void findans(vector<int>&res,vector<int>&nums,vector<vector<int>>&ans,int freq[]){
      if (res.size() == nums.size()) {
        ans.push_back(res);
        return;
      }
      for (int i = 0; i < nums.size(); i++) {
        if (!freq[i]) {
          res.push_back(nums[i]);
          freq[i] = 1;
          findans(res, nums, ans, freq);
          freq[i] = 0;
          res.pop_back();
        }
      }
    }
  public:
    vector<vector<int>>permute(vector<int>&nums){
      vector<vector<int>>ans;
      vector<int>res;
      int freq[nums.size()];
      for (int i=0;i<nums.size();i++) freq[i]=0;
      findans(res, nums, ans, freq);
      return ans;
    }

};