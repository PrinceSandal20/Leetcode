class Solution {
public:
    long long mode=1e9+7;
    int find(int start,int finish,int fuel,vector<int>&locations,vector<vector<int>>&dp){
        if(fuel<0)return 0;
        if(dp[start][fuel]!=-1)return dp[start][fuel];
        int ans=0;
        if(start==finish)ans++;
        for(int i=0;i<locations.size();i++){
            if(i!=start && abs(locations[i]-locations[start])<=fuel){
                ans=((ans)%mode+find(i,finish,fuel-abs(locations[i]-locations[start]),locations,dp)%mode)%mode;
            }
        }
        return dp[start][fuel]=ans%mode;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>>dp(locations.size(),vector<int>(fuel+1,-1));
        return find(start,finish,fuel,locations,dp);
    }
};