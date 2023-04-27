class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0,j=0,ans=0,cnt=0;
        while(j<nums.size()){
            if(nums[j]==0){
                cnt++;
            }
            while(i<=j && cnt>1){
                if(nums[i]==0){
                    cnt--;
                }
                i++;
            }
            ans=max(ans,j-i);
            j++;
        }
        return ans;
    }
};