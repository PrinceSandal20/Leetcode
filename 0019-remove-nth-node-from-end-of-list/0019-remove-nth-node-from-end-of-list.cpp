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
    ListNode* rev(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* p=rev(head->next);
        head->next->next=head;
        head->next=NULL;
        return p;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* x=rev(head);
        ListNode* temp=NULL;
        ListNode* del=x;
        int count=0;
        while(del!=NULL){
            count++;
            if(del==x && temp==NULL && count==n){
                x=del->next;
                del->next=NULL;
            }
            else if(del!=x && count==n){
                temp->next=del->next;
                del->next=NULL;
            }
            temp=del;
            del=del->next;
        }
        return rev(x);
    }
};