/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL)return head;
        Node* temp=head;
        Node* tail=head;
        stack<Node*>st;
        while(temp!=NULL){
            if(temp->child)
            {
                Node* chld=temp->child;
                if(temp->next!=NULL){
                    st.push(temp->next);
                    temp->next->prev=NULL;
                }
                temp->next=chld;
                chld->prev=temp;
                temp->child=NULL;
            }
            tail=temp;
            temp=temp->next;
        }
        while(!st.empty()){
            temp=st.top();
            st.pop();
            tail->next=temp;
            temp->prev=tail;
            while(temp!=NULL){
                tail=temp;
                temp=temp->next;
            }
        }
        return head;
    }
};