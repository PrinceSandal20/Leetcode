class Solution {
public:
    string removeTrailingZeros(string nums) {
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]=='0'){
                nums[i]='#';
            }
            else{
                break;
            }
        }
        string ans="";
        for(auto val:nums){
            if(val!='#'){
                ans+=val;
            }
        }
        return ans;
    }
};