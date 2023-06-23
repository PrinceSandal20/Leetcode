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
    bool wordBreak(string s, vector<string>& wordDict) {
        Node* root=new Node();
        for(auto &val:wordDict){
            insert(val,root);
        }
        vector<int>dp(s.size()+1,0);
        dp[0]=1;
        for(int i=1;i<=s.size();i++){
            for(int j=0;j<i;j++){
                if(dp[j] && search(s.substr(j,i-j),root)){
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};