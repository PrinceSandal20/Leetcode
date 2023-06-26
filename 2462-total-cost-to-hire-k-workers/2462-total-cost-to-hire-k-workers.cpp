class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candi) {
        priority_queue<int,vector<int>,greater<int>>minH1,minH2;
        long long ans=0;
        for(int i=0;i<candi;i++){
            minH1.push(costs[i]);
        }
        int t=costs.size();
        for(int i=max(candi,t-candi);i<costs.size();i++){
            minH2.push(costs[i]);
        }
        int start=candi;
        int end=t-candi-1;
        for(int i=0;i<k;i++){
            if(minH2.empty() || !minH1.empty() && minH1.top()<=minH2.top()){
                ans+=minH1.top();
                minH1.pop();
                if(start<=end){
                    minH1.push(costs[start++]);
                }
            }
            else{
                ans+=minH2.top();
                minH2.pop();
                if(start<=end){
                    minH2.push(costs[end--]);
                }
            }
        }
        return ans;
    }
};