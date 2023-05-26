class Solution {
public:
    vector<int> pref(vector<int>&v){
        int n=v.size();
        vector<int>lps(n,0);
        int i=1,j=0;
        while(i<n){
            if(v[i]==v[j]){
                lps[i]=j+1;
                i++,j++;
            }
            else{
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return lps;
    }
    int helppref(vector<int>&v1,vector<int>&v2){
        vector<int>lps(v2.size(),0);
        lps=pref(v2);
        int i=0,j=0,ans=0,len=0;
        while(i<v1.size()){
            if(v1[i]==v2[j]){
                i++,j++;
                len++;
                ans=max(ans,len);
            }
            else{
                if(j!=0){
                    j=lps[j-1];
                    len=j;
                }
                else{
                    i++;
                    len=0;
                }
            }
            if(j==v2.size()){
                break;
            }
        }
        return ans;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        for(int i=0;i<nums1.size();i++){
            vector<int>v(nums1.begin()+i,nums1.end());
            ans=max(ans,helppref(nums2,v));
        }
        for(int i=0;i<nums2.size();i++){
            vector<int>v(nums2.begin()+i,nums2.end());
            ans=max(ans,helppref(nums1,v));
        }
        return ans;
    }
};