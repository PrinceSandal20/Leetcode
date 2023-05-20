class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int>ans,xr(nums.size());
        xr[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            xr[i]=xr[i-1]^nums[i];
        }
        int val=pow(2,maximumBit)-1;
        for(int i=nums.size()-1;i>=0;i--){
                xr[i]=val-xr[i];
                ans.push_back(xr[i]);
        }
        return ans;
    }
};