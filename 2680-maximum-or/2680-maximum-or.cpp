class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        long long ans=0;
        vector<int>pref(nums.size(),0),suff(nums.size(),0);
        // pref[0]=nums[0];
        // suff[suff.size()-1]=nums[nums.size()-1];
        for(int i=1;i<nums.size();i++){
            pref[i]=(pref[i-1]|nums[i-1]);
        }
        for(int i=nums.size()-2;i>=0;i--){
            suff[i]=suff[i+1]|nums[i+1];
        }
        for(int i=0;i<nums.size();i++){
            long long val=nums[i];
            val*=pow(2,k);
            ans=max(ans,pref[i]|val|suff[i]);
        }
        return ans;
    }
};