class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jump=nums[0];
        if(jump==0 && nums.size()!=1){
            return false;
        }
        for(int i=1;i<nums.size();i++)
        {
            jump--;
            if(nums[i]>jump){
                jump=nums[i];
            }
            if(i!=nums.size()-1 && jump==0){
               return  false;
            }
        }
        return true;
    }
};