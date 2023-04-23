class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int i=0,j=0;
        vector<int>ans;
        map<int,int>m;
        while(j<nums.size()){
            m[nums[j]]++;
            while(j-i+1>k){
                m[nums[i]]--;
                if(m[nums[i]]==0){
                    m.erase(nums[i]);
                }
                i++;
            }
            if(j-i+1==k){
                int mn=INT_MAX,cnt=0;
                for(auto val:m){
                    cnt+=val.second;
                    if(cnt>=x){
                        mn=val.first;
                        break;
                    }
                    else{
                        mn=INT_MAX;
                    }
                }
                if(mn==INT_MAX || mn>0){
                    ans.push_back(0);
                }
                else{
                    ans.push_back(mn);
                }
            }
            j++;
        }
        return ans;
    }
};