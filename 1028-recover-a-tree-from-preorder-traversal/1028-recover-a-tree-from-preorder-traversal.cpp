/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
       vector<pair<int,int>>vp;
       int level=0,digit=0;
       for(int i=0;i<traversal.size();i++)
       {
           if(traversal[i]=='-'){
               level++;
           }
           else{
               while(i<traversal.size() && traversal[i]>='0' && traversal[i]<='9'){
                   digit=digit*10+traversal[i]-'0';
                   i++;
               }
               i--;
               vp.push_back({digit,level});
               digit=0;
               level=0;
           }
       }
       TreeNode* root=new TreeNode(vp[0].first);
       stack<pair<TreeNode*,int>>st;
       st.push({root,vp[0].second});
       for(int i=1;i<vp.size();i++){
           cout<<vp[i].second<<endl;
           if(vp[i].second-st.top().second==1){
               cout<<"x"<<endl;
               TreeNode* x=new TreeNode(vp[i].first);
               if(st.top().first->left==NULL){
                   st.top().first->left=x;
               }
               else{
                   st.top().first->right=x;
               }
               st.push({x,vp[i].second});
           }
           else{
               while(!st.empty() && vp[i].second-st.top().second!=1){
                   st.pop();
               }
               if(vp[i].second-st.top().second==1){
               TreeNode* x=new TreeNode(vp[i].first);
               if(st.top().first->left==NULL){
                   st.top().first->left=x;
               }
               else{
                   st.top().first->right=x;
               }
               st.push({x,vp[i].second});
              }
           }
       }
       return root;
    }
};