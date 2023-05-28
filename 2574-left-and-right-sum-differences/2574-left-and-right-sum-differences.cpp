class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
      int n=nums.size();
      vector<int>left(n),right(n);
      left[0]=nums[0],right[n-1]=nums[n-1];
      for(int i=1;i<n;i++){
          left[i]=left[i-1]+nums[i];
      }
      for(int i=n-2;i>=0;i--){
          right[i]=right[i+1]+nums[i];
      }
      left.pop_back();
      left.insert(left.begin(),0);
      right.erase(right.begin());
      right.push_back(0);
      vector<int>ans;
      for(int i=0;i<n;i++){
          ans.push_back(abs(left[i]-right[i]));
      }
      return ans;
    }
};