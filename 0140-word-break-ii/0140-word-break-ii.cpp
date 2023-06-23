class Node{
    Node* links[26];
    bool flag=false;
public:
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
class Solution {
    private:
    void insert(string words,Node* root){
        int n=words.size();
        Node* node=root;
        for(int i=0;i<n;i++){
            if(!node->contains(words[i])){
                node->put(words[i],new Node());
            }
            node=node->get(words[i]);
        }
        return node->setend();
    }
    bool search(string word,Node* root) {
        int n = word.size();
        Node* node = root;
        for(int i = 0; i < n; i++) {
            if(!node->contains(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isend();
    }
public:
    vector<string>ans;
    void dfs(int idx,string ds,string &s,Node* root){
        if(idx==s.size()){
            ans.push_back(ds.substr(0,0+ds.size()-1));
            return ;
        }
        string str="";
        for(int i=idx;i<s.size();i++){
            str.push_back(s[i]);
            if(search(str,root)){
                dfs(i+1,ds+str+" ",s,root);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Node* root=new Node();
        for(auto &val:wordDict){
            insert(val,root);
        }
        dfs(0,"",s,root);
        return ans;
    }
};