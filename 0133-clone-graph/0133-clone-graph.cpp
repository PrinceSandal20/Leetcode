/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)return NULL;
        unordered_map<Node*,Node*>m;
        Node* root=new Node(node->val,{});
        m[node]=root;
        queue<Node*>q;
        q.push(node);
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            for(Node* cur:temp->neighbors){
                if(!m.count(cur)){
                    m[cur]=new Node(cur->val,{});
                    q.push(cur);
                }
               m[temp]->neighbors.push_back(m[cur]);
            }
        }
        return root;
    }
};