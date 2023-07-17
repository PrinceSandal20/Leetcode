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
    private:
    stack<int> rev(ListNode* head){
        stack<int>st;
        ListNode* temp=head;
        while(temp!=NULL){
            st.push(temp->val);
            temp=temp->next;
        }
        return st;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>st1=rev(l1);
        stack<int>st2=rev(l2);
        ListNode* temp=NULL;
        int carry=0;
        while(!st1.empty() || !st2.empty() || carry!=0){
            int sum=carry;
            if(!st1.empty()){
                sum+=st1.top();
                st1.pop();
            }
            if(!st2.empty()){
                sum+=st2.top();
                st2.pop();
            }
            ListNode* n=new ListNode(sum%10);
            n->next=temp;
            temp=n;
            carry=sum/10;
        }
        return temp;
    }
};