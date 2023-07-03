class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int>ans(heights.size(),0);
        stack<int>st;
        st.push(heights.size()-1);
        for(int i=heights.size()-2;i>=0;i--){
            int c=0;
            while(!st.empty() && heights[i]>heights[st.top()]){
                c++;
                st.pop();
            }
            if(st.size()==0){
               ans[i]=c;
            }
            else{
                ans[i]=c+1;
            }
            st.push(i);
        }
        return ans;
    }
};