class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        long long ans=0,mode=1e9+7;
        for(int i=31;i>=0;i--){
            long long set=0,unset=0;
            for(int j=0;j<nums.size();j++){
                if(nums[j] & (1<<i)){
                    set++;
                }
                else{
                    unset++;
                }
            }
            ans=(ans+(set*unset)%mode)%mode;
        }
        return (ans)%mode;
    }
};