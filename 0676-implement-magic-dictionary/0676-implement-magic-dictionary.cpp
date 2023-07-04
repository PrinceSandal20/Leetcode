class Node {
    public:
    Node *links[26]={NULL};
    bool flag = false;
};
class MagicDictionary {
    Node* root;
public:
    MagicDictionary() {
        root=new Node();
    }
    void insert(string word) {
        Node *node = root;
        for(auto &c:word) {
            int idx=c-'a';
            if(node->links[idx]==NULL){
                node->links[idx]=new Node();
            }
            node=node->links[idx];
        }
        node->flag=true;
    }
    void buildDict(vector<string> dictionary) {
        for(int i=0;i<dictionary.size();i++){
            insert(dictionary[i]);
        }
    }
    
    bool find(string word) {
        Node* node = root;
        for(auto &c:word){
            int idx=c-'a';
            if(node->links[idx]==NULL){
                return false;
            }
            node=node->links[idx];
        }
        return node->flag;
    }
    bool search(string word) {
        for(int i=0;i<word.size();i++)
        {
            string temp=word;
            for(int j=0;j<26;j++)
            {
                if('a'+j!=word[i]){
                    temp[i]='a'+j;
                    if(find(temp)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */