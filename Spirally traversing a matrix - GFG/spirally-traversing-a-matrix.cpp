//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    vector<int>ans;
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&matrix,int n,int m){
        if(row<0 || row>n || col<0 || col>m || vis[row][col]==1){
            return;
        }
        if(!vis[row][col]){
            ans.push_back(matrix[row][col]);
            vis[row][col]=1;
        }
        if(row<=col+1){
            dfs(row,col+1,vis,matrix,n,m);
        }
        dfs(row+1,col,vis,matrix,n,m);
        dfs(row,col-1,vis,matrix,n,m);
        dfs(row-1,col,vis,matrix,n,m);
    }
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<vector<int>> vis(r,vector<int>(c,0));
        dfs(0,0,vis,matrix,r-1,c-1);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends