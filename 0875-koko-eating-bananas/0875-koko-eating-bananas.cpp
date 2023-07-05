class Solution {
public:
    long long find(vector<int>&arr,int mid){
        long long time=0;
        for(int i=0;i<arr.size();i++)
        {
            time+=ceil(arr[i]/(double)mid);
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int i=1;
        int j=*max_element(piles.begin(),piles.end());
        int ans=INT_MAX;
        while(i<=j){
            int mid=i+(j-i)/2;
            long long totalh=find(piles,mid);
            if(totalh<=h){
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