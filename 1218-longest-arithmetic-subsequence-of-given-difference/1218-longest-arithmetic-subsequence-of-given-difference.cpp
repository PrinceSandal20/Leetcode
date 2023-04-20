class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int,int> m;
        for(int i=arr.size()-1;i>=0;i--){
            if(m.count(arr[i]+difference)>0){
                m[arr[i]]=1+m[arr[i]+difference];
            }
            else{
                m[arr[i]]=1;
            }
        }
        int ans=0;
        for(auto i:m){
            ans=max(ans,i.second);
        }
        return ans;
    }
};