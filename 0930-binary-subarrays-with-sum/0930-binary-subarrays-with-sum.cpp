class Solution {
public:
    int window(vector<int>&nums,int k){
        long long i=0,j=0,ans=0,sum=0;
        if(k<0)return 0;
        while(j<nums.size()){
            sum+=nums[j];
            if(sum>k){
                 while(sum>k && i<nums.size()){
                    sum-=nums[i];
                    i++;
                }
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int k) {
        return window(nums,k)-window(nums,k-1);
    }
};