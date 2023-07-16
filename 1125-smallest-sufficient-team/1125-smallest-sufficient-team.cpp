class Solution {
    private:
    int dp[1<<16][64];
    bool choice[1<<16][64];
    private:
    int find(int i,int mask,int m,int req_mask,vector<int>&people){
        if(mask==req_mask)return 0;
        if(i==m)return 100000;
        if(dp[mask][i]!=-1)return dp[mask][i];
        int take=1+find(i+1,mask|people[i],m,req_mask,people);
        int not_take=find(i+1,mask,m,req_mask,people);
        if(take<not_take){
            choice[mask][i]=1;
        }
        return dp[mask][i]=min(take,not_take);
    }
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        //store the index of req_skills in map to get the mask of peeps
        int n=req_skills.size();
        int m=people.size();
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            mp[req_skills[i]]=i;
        }
        vector<int>mask_people;
        //traversing people and storing mask of every people skills
        for(auto skill:people){
            int mask=0;
            for(auto val:skill){
                mask|=(1<<mp[val]);
            }
            mask_people.push_back(mask);
        }
        int req_mask=(1<<n)-1;
        memset(dp,-1,1<<(n+8));
        memset(choice,0,(1<<n)+6);
        //trying all possible ways to find min team and setting the idx true
        find(0,0,m,req_mask,mask_people);
        vector<int>ans;
        for(int i=0,mask=0;i<m;i++){
            if(choice[mask][i]){
                ans.push_back(i);
                mask|=mask_people[i];
            }
            if(mask==req_mask)break;
        }
        return ans;
    }
};