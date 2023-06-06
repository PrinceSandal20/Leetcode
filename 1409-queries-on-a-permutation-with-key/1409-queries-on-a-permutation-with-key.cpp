class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int>ans;
        list<int>l;
        for(int i=1;i<=m;i++){
            l.push_back(i);
        }
        for(int i=0;i<queries.size();i++){
            auto ele=find(l.begin(),l.end(),queries[i]);
            ans.push_back(distance(l.begin(),ele));
            if(ele!=l.begin()){
                l.splice(l.begin(),l,ele,next(ele));
            }
        }
        return ans;
    }
};