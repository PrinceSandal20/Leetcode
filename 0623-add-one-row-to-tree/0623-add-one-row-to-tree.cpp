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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root==NULL){
            return NULL;
        }
        if(depth==1){
            TreeNode *newnode= new TreeNode(val);        
            newnode->left=root;                          
            return newnode;
       }
        int level=1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            level++;
            while(n--){
                TreeNode* temp=q.front();
                q.pop();
                if(level==depth){
                    TreeNode* l1=temp->left;
                    TreeNode* x1=new TreeNode(val);
                    temp->left=x1;
                    x1->left=l1;
                    TreeNode* l2=temp->right;
                    TreeNode* x2=new TreeNode(val);
                    temp->right=x2;
                    x2->right=l2;
                }
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        return root;
    }
};