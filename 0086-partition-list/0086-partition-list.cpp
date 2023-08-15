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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL) return head;
        vector<int> ans,less,more,net;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            ans.push_back(temp->val);
            temp=temp->next;
        }
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]<x)
            {
                less.push_back(ans[i]);
            }
            if(ans[i]==x || ans[i]>x || ans[i]==x+1)
            {
                more.push_back(ans[i]);
            }
        }
        for(int i=0;i<less.size();i++)
        {
            net.push_back(less[i]);
        }
        for(int i=0;i<more.size();i++)
        {
            net.push_back(more[i]);
        }
        ListNode* n=new ListNode(net[0]);
        ListNode* t=n;
        for(int i=1;i<net.size();i++)
        {
            ListNode* x=new ListNode(net[i]);
            t->next=x;
            t=t->next;
        }
        return n;
    }
};