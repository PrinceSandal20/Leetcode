class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans=0,valid=0,count=0;
        int i=0,j=0;
        while(j<nums.size()){
            if(nums[j]%2!=0){
                valid++;
                count=0;
            }
            while(valid==k){
                if(nums[i]%2!=0){
                    valid--;
                }
                count++;
                i++;
            }
            ans+=count;
            j++;
        }
        return ans;
    }
};