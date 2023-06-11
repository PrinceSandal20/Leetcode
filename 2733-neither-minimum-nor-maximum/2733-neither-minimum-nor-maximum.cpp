class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int mn=*min_element(nums.begin(),nums.end());
        int mx=*max_element(nums.begin(),nums.end());
        for(auto val:nums){
            if(val!=mn && val!=mx){
                return val;
            }
        }
        return -1;
    }
};