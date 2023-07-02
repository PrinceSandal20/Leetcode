class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]==target)return true;

            if(nums[mid]==nums[i] && nums[mid]==nums[j]){
                //trim down the search space
                i++,j--;
                continue;
            }
            //left sorted
            if(nums[i]<=nums[mid]){
                if(target>=nums[i] && target<=nums[mid]){
                    j=mid-1;
                }
                else{
                    i=mid+1;
                }
            }
            //right sorted
            else{
                if(target>=nums[mid] && target<=nums[j]){
                    i=mid+1;
                }
                else{
                    j=mid-1;
                }
            }
        }
        return false;
    }
};