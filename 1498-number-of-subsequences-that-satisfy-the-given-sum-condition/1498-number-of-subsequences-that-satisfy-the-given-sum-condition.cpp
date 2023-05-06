class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int ans=0;
        int mod=1e9+7;
        sort(nums.begin(),nums.end());
        vector<int>pow(nums.size());
        pow[0]=1;
        for(int i=1;i<nums.size();i++)
        {
            pow[i]=(pow[i-1]*2)%mod;
            //cout<<pow[i]<<endl;
        }
        int i=0,j=nums.size()-1;
        while(i<=j){
            if(nums[i]+nums[j]<=target){
                ans+=pow[j-i];
                //cout<<ans<<" ans "<<endl;
                ans=ans%mod;
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};