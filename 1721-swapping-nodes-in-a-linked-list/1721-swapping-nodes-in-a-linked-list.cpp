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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp1=head;
        ListNode* temp2=head;
        ListNode* temp=head;
        int count1=1,count2=1;
        int count=0;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        while(temp1->next!=NULL && count1<k)
        {
            temp1=temp1->next;
            count1++;
        }
        while(temp2->next!=NULL && count2<(count-k+1))
        {
            temp2=temp2->next;
            count2++;
        }
        int ans1=temp1->val;
        int ans2=temp2->val;
        temp1->val=ans2;
        temp2->val=ans1;
        return head;
    }
};