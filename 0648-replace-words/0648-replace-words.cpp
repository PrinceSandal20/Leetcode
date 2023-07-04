struct Node{
    Node* links[26]={NULL};
    bool end=false;
};
class Solution {
    private: Node* root=new Node();
    private:
       void insert(string &word){
           Node* node=root;
           for(auto &c:word){
               int idx=c-'a';
               if(node->links[idx]==NULL){
                   node->links[idx]=new Node();
               }
               node=node->links[idx];
           }
           node->end=true;
       }
    private:
      string startswith(string &word){
          string s="";
          Node* node=root;
          for(auto &c:word){
               int idx=c-'a';
               if(node->links[idx]==NULL){
                   return word;
               }
               s+=c;
               node=node->links[idx];
               if(node->end)return s;
           }
           return word;
      }
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans="",temp="";
        for(auto &val:dictionary){
            insert(val);
        }
        stringstream ss(sentence);
        while(ss>>temp){
            ans+=startswith(temp);
            ans+=' ';
        }
        ans.pop_back();
        return ans;
    }
};