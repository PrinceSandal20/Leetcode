class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0,altitu=0;
        for(int i=0;i<gain.size();i++){
            altitu+=gain[i];
            ans=max(ans,altitu);
        }
        return ans;
    }
};