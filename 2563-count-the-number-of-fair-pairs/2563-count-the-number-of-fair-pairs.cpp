class Solution {
public: 
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long ans=0;
        // int i=0,j=nums.size()-1;
        // while(i<j){
        //     if(nums[i]+nums[j]<=upper && nums[i]+nums[j]>=lower){
        //         int k=i+1;
        //         while(k<j){
        //            if(nums[i]+nums[k]>=lower){
        //                break;
        //            }
        //             k++;
        //         }
        //         ans+=j-k+1;
        //         i++;
        //     }
        //     else if(nums[i]+nums[j]>upper){
        //         j--;
        //     }
        //     else if(nums[i]+nums[j]<lower){
        //         i++;
        //     }
        // }
        for(int i=0;i<nums.size()-1;i++)
        {
            
            int idx1=lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i])-nums.begin();
            int idx2=upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i])-nums.begin();
            ans+=idx2-idx1;
        }
        return ans;
    }
};