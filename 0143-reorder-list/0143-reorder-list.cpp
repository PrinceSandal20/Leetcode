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
    void reorderList(ListNode* head) {
        stack<ListNode*>st;
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            st.push(temp);
            count++;
            temp=temp->next;
        }
        //cout<<count;
        temp=head;
        for(int i=0;i<count;i=i+2){
            ListNode* node=st.top();
            st.pop();
            node->next=temp->next;
            temp->next=node;
            temp=temp->next->next;
        }
        temp->next=NULL;
    }
};