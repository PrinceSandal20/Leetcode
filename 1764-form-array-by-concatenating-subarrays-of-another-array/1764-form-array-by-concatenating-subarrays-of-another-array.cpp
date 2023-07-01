class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int k=0;
        int winsize=groups[k].size();
        vector<int>test;
        int i=0,j=0,count=0;
        while(j<nums.size()){
            test.push_back(nums[j]);
            if(j-i+1<winsize){
                j++;
            }
            else if(j-i+1==winsize){
                if(test==groups[k]){
                    count++;
                    if(k!=groups.size()-1){
                        k++;
                        winsize=groups[k].size();
                    }
                    //cout<<i<<" "<<j<<endl;
                    test.clear();
                    j++;
                    i=j;
                }
                else{
                    test.erase(test.begin());
                    i++,j++;
                }
            }
        }
       // cout<<count;
        return count==groups.size();
    }
};