class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string>q;
        unordered_map<string,int>vis;
        q.push(start);
        vis[start]=1;
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string node=q.front();
                q.pop();
                if(node==end){
                    return ans;
                }
                for(auto val:"ACGT"){
                    for(int i=0;i<node.size();i++){
                        string test=node;
                        test[i]=val;
                        if(!vis.count(test) && find(bank.begin(),bank.end(),test)!=bank.end()){
                            vis[test]=1;
                            q.push(test);
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};