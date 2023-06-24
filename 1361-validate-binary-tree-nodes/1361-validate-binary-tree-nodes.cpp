class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int>adj[n],ind(n,0);
        int edge=0;
        for(int i=0;i<leftChild.size();i++){
            if(leftChild[i]!=-1){
                adj[i].push_back(leftChild[i]);
                ind[leftChild[i]]++;
                edge++;
            }
            if(rightChild[i]!=-1){
                adj[i].push_back(rightChild[i]);
                ind[rightChild[i]]++;
                edge++;
            }
        }
        queue<int>q;
        int x1=0;
        for(int i=0;i<ind.size();i++){
            if(ind[i]==0){
                q.push(i);
                x1++;
            }
            if(ind[i]>1){
                return false;
            }
        }
        vector<int>vis(n,0);
        while(!q.empty()){
            int node=q.front();
            vis[node]=1;
            q.pop();
            for(auto val:adj[node]){
                ind[val]--;
                if(vis[val]==0 && ind[val]==0){
                    cout<<val;
                    q.push(val);
                    x1++;
                }
            }
        }
        cout<<x1;
        if(x1!=n || edge!=n-1){
            return false;
        }
        return true;
    }
};