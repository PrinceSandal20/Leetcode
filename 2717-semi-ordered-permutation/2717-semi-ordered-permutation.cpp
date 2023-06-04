class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n=nums.size();
        int pos1=-1,pos2=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                pos1=i;
            }
            if(nums[i]==n){
                pos2=i;
            }
        }
        if(pos1>pos2){
            return pos1+(n-pos2-1)-1;
        }
        return pos1+(n-pos2-1);
    }
};