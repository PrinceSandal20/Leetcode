class Solution {
public:
    void findans(int idx,int count,int &ans,vector<int>&transfer,vector<vector<int>>& requests){
        if(idx==requests.size()){
            for(auto val:transfer){
                if(val!=0)return ;
            }
            ans=max(ans,count);
            return ;
        }
        transfer[requests[idx][0]]--;
        transfer[requests[idx][1]]++;
        findans(idx+1,count+1,ans,transfer,requests);
        transfer[requests[idx][0]]++;
        transfer[requests[idx][1]]--;
        findans(idx+1,count,ans,transfer,requests);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int>transfer(n,0);
        int ans=0;
        findans(0,0,ans,transfer,requests);
        return ans;
    }
};