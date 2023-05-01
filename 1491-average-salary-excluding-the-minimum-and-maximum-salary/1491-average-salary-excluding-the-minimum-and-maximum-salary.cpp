class Solution {
public:
    double average(vector<int>& salary) {
        double ans=0;
        int mn=*min_element(salary.begin(),salary.end());
        int mx=*max_element(salary.begin(),salary.end());
        for(auto val:salary){
            if(val!=mn && val!=mx){
                ans+=(double)val;
            }
        }
        int x=salary.size()-2;
        return ans/(double)x;
    }
};