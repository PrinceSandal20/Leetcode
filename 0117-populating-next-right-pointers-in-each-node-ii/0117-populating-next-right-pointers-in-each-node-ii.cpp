/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
   Node* connect(Node* root) {
        if(root==NULL){
            return NULL;
        }
        vector<vector<Node*>>ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<Node*>res;
            for(int i=0;i<n;i++){
                Node* temp=q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                res.push_back(temp);
            }
            res.push_back(NULL);
            ans.push_back(res);
        }
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size()-1;j++){
                ans[i][j]->next=ans[i][j+1];
            }
        }
        return root;
   }
};