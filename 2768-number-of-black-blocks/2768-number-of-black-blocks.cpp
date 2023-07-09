class Solution {
    private:
    bool isvalid(int x,int y,int n,int m){
        if(x>=0 && x<n && y>=0 && y<m)return true;
        return false;
    }
    bool ispresent(set<pair<int,int>>&st,int x,int y){
        return st.find({x,y})!=st.end();
    }
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        set<pair<int,int>>st;
        for(int i=0;i<coordinates.size();i++){
            st.insert({coordinates[i][0],coordinates[i][1]});
        }
        vector<long long>ans(5,0);
        for(int i=0;i<coordinates.size();i++){
            int x=coordinates[i][0],y=coordinates[i][1];
            if(isvalid(x+1,y,m,n) && isvalid(x,y+1,m,n) && isvalid(x+1,y+1,m,n)){
                int count=1;
                count+=ispresent(st,x+1,y)+ispresent(st,x,y+1)+ispresent(st,x+1,y+1);
                ans[count]++;
            }
            if(isvalid(x,y-1,m,n) && isvalid(x+1,y,m,n) && isvalid(x+1,y-1,m,n)){
                int count=1;
                count+=ispresent(st,x,y-1)+ispresent(st,x+1,y)+ispresent(st,x+1,y-1);
                ans[count]++;
            }
            if(isvalid(x-1,y,m,n) && isvalid(x-1,y+1,m,n) && isvalid(x,y+1,m,n)){
                int count=1;
                count+=ispresent(st,x-1,y)+ispresent(st,x-1,y+1)+ispresent(st,x,y+1);
                ans[count]++;
            }
            if(isvalid(x-1,y,m,n) && isvalid(x,y-1,m,n) && isvalid(x-1,y-1,m,n)){
                int count=1;
                count+=ispresent(st,x-1,y)+ispresent(st,x,y-1)+ispresent(st,x-1,y-1);
                ans[count]++;
            }
        }
        ans[0]=(long long)(n-1)*(m-1);
        long long tot=0;
        for(int i=1;i<5;i++){
            ans[i]=ans[i]/i;
            tot+=ans[i];
        }
        ans[0]-=tot;
        return ans;
    }
};