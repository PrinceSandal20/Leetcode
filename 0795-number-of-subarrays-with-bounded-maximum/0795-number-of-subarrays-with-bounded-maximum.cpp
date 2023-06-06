class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n=nums.size();
        int i=0,j=0,mx=0;
        int ans=0;
        while(j<n){
            if(nums[j]>=left && nums[j]<=right){
                mx=j-i+1;
            }
            else if(nums[j]>right){
                i=j+1;
                mx=0;
            }
            ans+=mx;
            j++;
        }
        return ans;
    }
};