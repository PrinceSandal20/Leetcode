class Solution {
public: 
    int dfs(int idx,int k,vector<int>&nums){
        if(k<0){
            return idx;
        }
        else
            return dfs((idx+1)%nums.size(),k-nums[(idx+1)%nums.size()],nums);
    }
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum=0,K=(long long)k;
        for(auto val:chalk){
            sum+=val;
        }
        if(chalk.size()==1){
            return 0;
        }
        return dfs(-1,K%sum,chalk);
    }
};