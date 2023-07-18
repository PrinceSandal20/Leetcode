class Solution {
    private:
    int largestRectangleArea(vector<int>& A) {
        vector<int>left;
        stack<int>st;
        st.push(0);
        left.push_back(-1);
        for(int i=1;i<A.size();i++){
            while(!st.empty() && A[st.top()]>=A[i]){
                st.pop();
            }
            if(st.size()==0){
                left.push_back(-1);
            }
            else{
                left.push_back(st.top());   
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        vector<int>right;
        st.push(A.size()-1);
        right.push_back(A.size());
        for(int i=A.size()-2;i>=0;i--){
            while(!st.empty() && A[st.top()]>=A[i]){
                st.pop();
            }
            if(st.size()==0){
                right.push_back(A.size());
            }
            else{
                right.push_back(st.top());   
            }
            st.push(i);
        }
        reverse(right.begin(),right.end());
        int ans=INT_MIN;
        for(int i=0;i<A.size();i++){
            ans=max(ans,(right[i]-left[i]-1)*A[i]);
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans=0;
        vector<int>arr(matrix[0].size());
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]=='1'){
                    arr[j]++;
                }
                else{
                    arr[j]=0;
                }
            }
            ans=max(ans,largestRectangleArea(arr));
        }
        return ans;
    }
};