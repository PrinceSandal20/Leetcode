class Solution {
public:
    bool dfs(int node,vector<int>&nums,vector<int>&vis,int dir){
        int neigh=(node+nums[node]+nums.size())%nums.size();
        if(node==neigh || nums[node]*dir<0){
            return false;
        }
        if(vis[neigh]){
            return true;
        }
        vis[neigh]=1;
        return dfs(neigh,nums,vis,dir);
    }
    bool circularArrayLoop(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                vector<int>vis(nums.size(),0);
                int dir=nums[i]>0?1:-1;
                if(dfs(i,nums,vis,dir)){
                    return true;
                }
            }
        }
        return false;
    }
};