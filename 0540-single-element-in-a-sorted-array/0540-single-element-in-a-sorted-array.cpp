class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-2;
        while(i<=j){
            int mid=i+(j-i)/2;
            if (mid % 2 == 0) {
                    if (nums[mid] != nums[mid + 1]) 
                        j= mid - 1; 
                    else
                      i= mid + 1; 
                } else {
                    if (nums[mid] == nums[mid + 1]) 
                        j = mid - 1; 
                    else
                        i = mid + 1; 
                }
        }
        return nums[i];
    }
};