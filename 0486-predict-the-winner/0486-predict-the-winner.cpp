class Solution {
    private:
    int findwinner(int i,int j,int flag,vector<int>&nums){
        if(i>j)return 0;
        int left=0,right=0,ans=0;
        if(flag==0){
            left=nums[i]+findwinner(i+1,j,1,nums);
            right=nums[j]+findwinner(i,j-1,1,nums);
            ans=max(left,right);
        }
        else{
            left=-nums[i]+findwinner(i+1,j,0,nums);
            right=-nums[j]+findwinner(i,j-1,0,nums);
            ans=min(left,right);
        }
        return ans;
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        return findwinner(0,nums.size()-1,0,nums)>=0;
    }
};