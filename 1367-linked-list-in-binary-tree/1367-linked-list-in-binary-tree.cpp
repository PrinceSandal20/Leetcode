/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool check(TreeNode* root,ListNode* head){
        if(head==NULL){
            return 1;
        }
        if(root==NULL || head->val!=root->val){
            return 0;
        }
        return check(root->left,head->next) || check(root->right,head->next);
    }
    bool dfs(TreeNode* root,ListNode* head){
        if(head==NULL){
            return 1;
        }
        if(root==NULL){
            return 0;
        }
        if(check(root,head)){
            return  1;
        }
        return dfs(root->left,head) || dfs(root->right,head);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(root,head);
    }
};