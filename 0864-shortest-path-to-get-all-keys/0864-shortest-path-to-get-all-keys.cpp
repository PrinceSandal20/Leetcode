class Solution {
public:
    int shortestPathAllKeys(vector<string>& s) {
        vector<vector<char>>grid(s.size(),vector<char>(s[0].size()));
        int mxlen=-1;
        queue<pair<int,pair<int,int>>>q;
        unordered_set<string>vis;
        for(int i=0;i<s.size();i++){
            for(int j=0;j<s[i].size();j++){
                grid[i][j]=s[i][j];
                if(grid[i][j]=='@'){
                    q.push({0,{i,j}});
                    vis.insert(to_string(0)+" "+to_string(i)+" "+to_string(j));
                }
                if(grid[i][j]>='a' && grid[i][j]<='f'){
                    mxlen=max(mxlen,grid[i][j]-'a'+1);
                }
            }
        }
        int ans=0;
        int delr[]={1,0,-1,0};
        int delc[]={0,1,0,-1};
        while(!q.empty()){
            int x=q.size();
            while(x--){
                int k=q.front().first;
                int r=q.front().second.first;
                int c=q.front().second.second;
                q.pop();
                if(k==(1<<mxlen)-1){
                    return ans;
                }
                for(int i=0;i<4;i++){
                    int nr=r+delr[i];
                    int nc=c+delc[i];
                    int key=k;
                    if(nr>=0 && nc>=0 && nr<=grid.size()-1 && nc<=grid[0].size()-1){
                        char ch=grid[nr][nc];
                        if(ch=='#')continue;
                        if(ch>='a' && ch<='f'){
                            //|forupdating bit
                            key|=1<<(ch-'a');
                        }
                        //&for checking bit present
                        if(ch>='A' && ch<='F' && (key&(1<<(ch-'A')))==0){
                            continue;
                        }
                        if(vis.count(to_string(key)+" "+to_string(nr)+" "+to_string(nc))==0){
                            vis.insert(to_string(key)+" "+to_string(nr)+" "+to_string(nc));
                            q.push({key,{nr,nc}});
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};