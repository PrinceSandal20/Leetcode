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
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        vector<int>ans;
        ListNode* temp=head;
        while(temp!=NULL){
            ans.push_back(temp->val);
            temp=temp->next;
        }
        for(int i=1;i<ans.size();i++){
            int j=i;
            while(j>0 && ans[j-1]>ans[j]){
                swap(ans[j-1],ans[j]);
                j--;
            }
        }
        ListNode* node=new ListNode(ans[0]);
        ListNode* t=node;
        for(int i=1;i<ans.size();i++){
            ListNode* x=new ListNode(ans[i]);
            t->next=x;
            t=t->next;
        }
        return node;
    }
};