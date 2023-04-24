class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxH;
        for(int i=0;i<stones.size();i++)
        {
            maxH.push(stones[i]);
        }
        while(maxH.size()>1)
        {
            int x=maxH.top();
            maxH.pop();
            int y=maxH.top();
            maxH.pop();
            maxH.push(x-y);
        }
        return maxH.top();
    }
};