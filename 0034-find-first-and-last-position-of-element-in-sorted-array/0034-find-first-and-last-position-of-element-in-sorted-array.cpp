class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int x=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int y=upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1;
        if(x==nums.size() || nums[x]!=target)return {-1,-1}; //edge cases
        return {x,y};
    }
};