class Solution {
public:
    struct Node {
        Node* links[26]={NULL};
        string word;
    };
    void insert(Node* root,string &word) {
        Node* node=root;
        for(auto &c:word){
            int idx=c-'a';
            if(node->links[idx]==NULL){
                node->links[idx]=new Node();
            }
            node=node->links[idx];
        }
        node->word=word;
    }
    void dfs(int row,int col,Node* trieroot,vector<string>&ans,vector<vector<char>>& board){
        if(row<0 || row>board.size()-1 || col<0 || col>board[0].size()-1 || !trieroot || board[row][col]=='0')return ;
        char ch=board[row][col];
        Node* trie=trieroot->links[ch-'a'];
        if(!trie)return;
        if(!trie->word.empty()){
            ans.push_back(trie->word);
            trie->word="";
        }
        board[row][col]='0';
        dfs(row-1,col,trie,ans,board);
        dfs(row+1,col,trie,ans,board);
        dfs(row,col-1,trie,ans,board);
        dfs(row,col+1,trie,ans,board);
        board[row][col]=ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* root=new Node();
        for(auto &val:words){
            insert(root,val);
        }
        vector<string>ans;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++) {
                dfs(i,j,root,ans,board);
            }
        }
        return ans;        
    }
};