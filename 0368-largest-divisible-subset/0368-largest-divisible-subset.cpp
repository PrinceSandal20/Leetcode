class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n,1),hash(n);
        int mx=1;
        int lastidx=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            if(dp[i]>mx){
                mx=dp[i];
                lastidx=i;
            }
        }
        vector<int>ans;
        ans.push_back(nums[lastidx]);
        int idx=1;
        while(hash[lastidx]!=lastidx){
            lastidx=hash[lastidx];
            ans.push_back(nums[lastidx]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        }
};
