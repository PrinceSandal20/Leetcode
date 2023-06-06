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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>m;
        unordered_set<int>bcha;
        for(int i=0;i<descriptions.size();i++){
            TreeNode* parent;
            TreeNode* child;
            if(m.find(descriptions[i][0])!=m.end()){
                parent=m[descriptions[i][0]];
            }
            else{
                parent = new TreeNode(descriptions[i][0]);
                m[descriptions[i][0]]=parent;
            }

            if(m.find(descriptions[i][1])!=m.end()){
                child = m[descriptions[i][1]];
                bcha.insert(descriptions[i][1]);
            }
            else{
                child = new TreeNode(descriptions[i][1]);
                m[descriptions[i][1]]=child;
                bcha.insert(descriptions[i][1]);
            }

            if(descriptions[i][2]==1){
                parent->left=child;
            }
            else{
                parent->right=child;
            }
        }
        for(int i=0;i<descriptions.size();i++){
            if(bcha.find(descriptions[i][0])==bcha.end()){
                return m[descriptions[i][0]];
            }
        }
        return NULL;
    }
};