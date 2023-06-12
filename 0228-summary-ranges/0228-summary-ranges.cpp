class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {   
        vector<string>ans;
        for(int i=0;i<nums.size();i++){
            int val=nums[i];
            while(i<nums.size()-1 && nums[i]==nums[i+1]-1){
                i++;
            }
            if(val!=nums[i]){
                ans.push_back(to_string(val)+"->"+to_string(nums[i]));
            }
            else{
                 ans.push_back(to_string(val));
            }
        }
        return ans;
    }
};