class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans=INT_MAX;
        int i=0,j=nums.size()-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            //left half sorted
            if(nums[i]<=nums[mid]){
                ans=min(ans,nums[i]);
                i=mid+1;
            }
            //right half sorted
            else{
                ans=min(ans,nums[mid]);
                j=mid-1;
            }
        }
        return ans;
    }
};