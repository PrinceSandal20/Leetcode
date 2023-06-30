//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}


// } Driver Code Ends


/*You are required to complete this method */
class Node{
    public:
    Node* links[26];
};
int countDistinctSubstring(string s)
{
    Node* root=new Node();
    int ans=0;
    for(int i=0;i<s.size();i++){
        Node* node=root;
        for(int j=i;j<s.size();j++){
            if(!node->links[s[j]-'a']){
                ans++;
                node->links[s[j]-'a']=new Node();
            }
            node=node->links[s[j]-'a'];
        }
    }
    return ans+1;
}