class Node{
public:
    Node* links[26];
    bool flag=false;
    bool contains(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setend(){
        flag=true;
    }
    bool isend(){
        return flag;
    }
};
void dfs(int i,Node *node,string word,bool &found){
    if(found)
    return ;
    if(i>=word.length()){
        if(node->isend())
          found=true;
        return ;
    }
    
        if(word[i]=='.'){
            for(int j=0;j<26;j++){
                char ch=(j+'a');
                if(node->contains(ch)){
                    dfs(i+1,node->get(ch),word,found);
                }
            }
        }
        else{
        if(node->contains(word[i]))
            dfs(i+1,node->get(word[i]),word,found);
        return ;
        }
    
}

class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        int n=word.size();
        Node* node=root;
        for(int i=0;i<n;i++){
            if(!node->contains(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setend();
    }
    
    bool search(string word) {
        Node* node=root;
        bool ans=false;
        dfs(0,node,word,ans);
        return ans;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */