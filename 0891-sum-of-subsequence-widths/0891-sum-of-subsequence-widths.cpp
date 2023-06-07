class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        long long  mode=1e9+7;
        int ans=0,n=nums.size();
        sort(nums.begin(),nums.end());
        vector<long>pow(n);
        pow[0]=1;
        for(int i=1;i<n;i++){
            pow[i]=pow[i-1]*2%mode;
        }
        for(int i=0;i<n;i++){
            ans=(ans+(pow[i]-pow[n-i-1])*nums[i])%mode;
        }
        return ans;
    }
};