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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* ans=new ListNode(0);
        ListNode* temp3=ans;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val==temp2->val){
                ListNode* n1=new ListNode(temp1->val);
                ListNode* n2=new ListNode(temp1->val);
                temp3->next=n1;
                temp3=temp3->next;
                temp3->next=n2;
                temp3=temp3->next;
                temp1=temp1->next;
                temp2=temp2->next;
            }
            else if (temp1->val>temp2->val){
                ListNode* n1=new ListNode(temp2->val);
                temp3->next=n1;
                temp3=temp3->next;
                temp2=temp2->next;
            }
            else if (temp1->val<temp2->val){
                ListNode* n1=new ListNode(temp1->val);
                temp3->next=n1;
                temp3=temp3->next;
                temp1=temp1->next;
            }
        }
        while(temp1!=NULL){
            ListNode* n1=new ListNode(temp1->val);
            temp3->next=n1;
            temp3=temp3->next;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            ListNode* n1=new ListNode(temp2->val);
            temp3->next=n1;
            temp3=temp3->next;
            temp2=temp2->next;
        }
        ListNode* t=ans->next;
        ans->next=NULL;
        return t;
    }
};