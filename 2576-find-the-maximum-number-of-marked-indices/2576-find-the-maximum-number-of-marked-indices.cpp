class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()/2;
        int count=0;
        while(i<nums.size()/2 && j<nums.size()){
            if(2*nums[i]<=nums[j]){
                i++,j++;
                count+=2;
            }
            else{
                j++;
            }
        }
        return count;
    }
};