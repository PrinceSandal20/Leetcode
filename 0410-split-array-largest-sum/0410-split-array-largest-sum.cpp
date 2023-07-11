class Solution {
    private:
    bool possible(int mid,int student,vector<int>&arr){
        int count=1;
        long long pagestud=0;
        for(int i=0;i<arr.size();i++){
            if(pagestud+arr[i]<=mid){
                pagestud+=arr[i];
            }
            else{
                count++;
                pagestud=arr[i];
            }
        }
        return count<=student;
    }
public:
    int splitArray(vector<int>&arr, int m) {
        int n=arr.size();
        if(n<m)return -1;
        int i=*max_element(arr.begin(),arr.end());
        int j=accumulate(arr.begin(),arr.end(),0);
        int ans;
        while(i<=j){
            int mid=(i+j)>>1;
            if(possible(mid,m,arr)){
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