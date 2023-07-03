class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans=0;
        int i=0,j=0;
        priority_queue<pair<int,int>>maxH;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minH;
        while(j<nums.size()){
            maxH.push({nums[j],j});
            minH.push({nums[j],j});
            //removing max from window
            while(maxH.top().second<i){
                maxH.pop();
            }
            //removing min from window
            while(minH.top().second<i){
                minH.pop();
            }
            if(abs(minH.top().first-maxH.top().first)<=limit){
                ans=max(ans,j-i+1);
                j++;
            }
            else{
                i++,j++;
            }
        }
        return ans;
    }
};