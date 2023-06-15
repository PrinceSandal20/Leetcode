//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void dfs(int row,int col,int n,int m,string ds,vector<string>&ans,vector<vector<int>>&grid){
        if(row<0 || col<0 || row>n || col>m || grid[row][col]==0){
            return ;
        }
        if(row==n && col==n){
            ans.push_back(ds);
            return ;
        }
        grid[row][col]=0;
        dfs(row+1,col,n,m,ds+"D",ans,grid);
        dfs(row-1,col,n,m,ds+"U",ans,grid);
        dfs(row,col+1,n,m,ds+"R",ans,grid);
        dfs(row,col-1,n,m,ds+"L",ans,grid);
        grid[row][col]=1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        dfs(0,0,n-1,n-1,"",ans,m);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends