class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans=0;
        int i=0,j=0;
        while(j<nums.size()){
            if(nums[j]%2==0){
                while(i<nums.size() && nums[j]<=threshold && nums[i]<=threshold && (i-j)%2==nums[i]%2){
                    i++;
                }
                ans=max(ans,i-j);
                j++;
                i=j;
            }
            else{
                i++,j++;
            }
        }
        return ans;
    }
};