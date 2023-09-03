class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long ans=0,sum=0;
        unordered_map<int,int>mp;
        int i=0,j=0;
        while(j<nums.size())
        {
            mp[nums[j]]++;
            sum+=(long long)nums[j];
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                if(mp.size()>=m){
                    if(ans<sum){
                        ans=sum;
                    }
                }
                mp[nums[i]]--;
                sum-=(long long)nums[i];
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                i++,j++;
            }
        }
        return ans;
    }
};