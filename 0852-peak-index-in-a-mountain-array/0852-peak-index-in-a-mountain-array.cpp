class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int ans;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]<nums[i])
            {
                ans=i;
            }
        }
        return ans;
    }
};