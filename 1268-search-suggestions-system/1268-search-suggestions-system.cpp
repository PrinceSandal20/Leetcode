class Node{
    public:
    Node *links[26] = {NULL};
    bool end = false;
};
class Solution {
public:
    void insert(Node *node, string &word) {
        for (char &c : word) {
            int index = c - 'a';
            if (!node->links[index])
                node->links[index] = new Node;
            node=node->links[index];
        }
        node->end=true;
    }
    vector<string> search(Node* node,string &prefix) {
        vector<string> res;
        for (char &c : prefix) {
            int index = c - 'a';
            if (!node->links[index])
                return {};
            node=node->links[index];
        }
        dfs(node,prefix,res);
        return res;
    }
    void dfs(Node* node,string pre, vector<string> &res) {
        if (res.size() == 3)
            return;
        if (node->end)
            res.push_back(pre);
        
        for (int i = 0; i < 26; i++) {
            if (node->links[i])
                dfs(node->links[i], pre + (char)(i + 'a'), res);
        }
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchword) {
        Node* node=new Node();
        for (string &prod : products)
            insert(node,prod);
        vector<vector<string>>ans;
        string prefix="";
        for (char &val:searchword) {
            prefix += val;
            ans.push_back(search(node,prefix));
        }
        return ans;
    }
};