class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum=0,idx,mn=INT_MAX;
        for(int i=0;i<gas.size();i++)
        {
            sum+=gas[i]-cost[i];
            //cout<<sum<<endl;
            if(mn>sum){
                mn=sum;
                idx=i;
                cout<<mn<<"->"<<i<<endl;
            }
        }
        if(sum<0)return -1;
        return (idx+1)%gas.size();
    }
};