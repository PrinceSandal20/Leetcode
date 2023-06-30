struct Node{
    Node* links[2];
    bool bitset(int bit){
        return links[bit]!=NULL;
    }
    void putbit(int bit,Node* node){
        links[bit]=node;
    }
    Node* getbit(int bit){
        return links[bit];
    }
};
class Trie{
    private:Node* root;
    public:
       Trie(){
           root=new Node();
       }
    public:
        void insertbit(int num){
            Node* node=root;
            for(int i=31;i>=0;i--){
                int bit=(num>>i)&1;
                if(!node->bitset(bit)){
                    node->putbit(bit,new Node());
                }
                node=node->getbit(bit);
            }
        }
    public:
        int getmaxxor(int num){
            Node* node=root;
            int mxxor=0;
            for(int i=31;i>=0;i--){
                int bit=(num>>i)&1;
                if(node->bitset(!bit)){
                    mxxor=mxxor|(1<<i);
                    node=node->getbit(!bit);
                }
                else{
                    node=node->getbit(bit);
                }
            }
            return mxxor;
        }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto &val:nums){
            trie.insertbit(val);
        }
        int ans=0;
        for(auto &val:nums){
            ans=max(ans,trie.getmaxxor(val));
        }
        return ans;
    }
};