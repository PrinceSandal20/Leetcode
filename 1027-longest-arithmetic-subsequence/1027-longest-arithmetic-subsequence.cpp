class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        if(nums.size()<=2){
            return nums.size();
        }
        int ans=0;
        unordered_map<int,int>m[nums.size()+1];
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=nums.size()-1;j>i;j--){
                if(m[j].count(nums[j]-nums[i])>0){
                    m[i][nums[j]-nums[i]]=1+m[j][nums[j]-nums[i]];
                }
                else{
                    m[i][nums[j]-nums[i]]=2;
                }
                ans=max(ans,m[i][nums[j]-nums[i]]);
            }
        }
        return ans;
    }
};