class Solution {
    private:
    bool check(vector<int>&dist,double hour ,int mid){
        double time=0;
        for(int i=0;i<dist.size();i++){
             if(i!=dist.size()-1){
                 time+=ceil(1.0*dist[i]/mid);
             }
             else{
                 time+=1.0*dist[i]/mid;
             }
             if(time>hour)return false;
        }
        return true;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int ans=-1;
        int i=1,j=1e7;
        while(i<=j){
            int mid=(i+j)>>1;
            if(check(dist,hour,mid)){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};