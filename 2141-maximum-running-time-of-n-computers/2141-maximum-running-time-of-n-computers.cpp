class Solution {
    private:
    bool ispossible(vector<int>&batteries,long long time,int computers){
        long long totaltime=0;
        for(auto bat_time:batteries){
            if(bat_time<time){
                totaltime+=bat_time;
            }
            else{
                totaltime+=time;
            }
        }
        return totaltime>=time*computers;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long ans=INT_MIN;
        long long i=0,j=1e14;
        while(i<=j){
            long long mid=(i+j)>>1;
            if(ispossible(batteries,mid,n)){
                ans=mid;
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return ans;
    }
};