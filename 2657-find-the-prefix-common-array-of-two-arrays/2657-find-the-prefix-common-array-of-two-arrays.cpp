class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>ans(A.size());
        set<int>st;
        for(int i=0;i<A.size();i++)
        {
            int cnt=0;
            for(int j=0;j<i+1;j++){
                st.insert(A[j]);
            }
            for(int j=0;j<i+1;j++){
                if(st.find(B[j])!=st.end()){
                    cnt++;
                }
            }
            ans[i]=cnt;
        }
        return ans;
    }
};