class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int ans1=0,ans2=0;
        for(int i=0;i<=n;i++){
            ans1=ans1^i;
        }
        for(int i=0;i<n;i++){
            ans2=ans2^nums[i];
        }
        int ans=ans1^ans2;
        int c=0;
        while(ans>0){
            if(ans&(1<<c)){
                break;
            }
            c++;
        }
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&(1<<c)){
                res=res^nums[i];
            }
        }
        for(int i=0;i<=n;i++){
            if(i&(1<<c)){
                res=res^i;
            }
        }
        return res;
    }
};