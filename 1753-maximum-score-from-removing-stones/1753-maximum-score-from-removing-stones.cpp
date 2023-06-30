class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int>maxH;
        maxH.push(a);
        maxH.push(b);
        maxH.push(c);
        int ans=0;
        while(maxH.size()>1){
            int val1=maxH.top();
            maxH.pop();
            int val2=maxH.top();
            maxH.pop();
            val1--;
            val2--;
            if(val1!=0){
                maxH.push(val1);
            }
            if(val2!=0){
                maxH.push(val2);
            }
            ans++;
        }
        return ans;
    }
};