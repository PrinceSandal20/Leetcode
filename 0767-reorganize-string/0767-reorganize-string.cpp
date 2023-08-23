class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>m;
        priority_queue<pair<int,char>> maxH;
        for(auto i:s)
        {
            m[i]++;
        }
        for(auto &i:m)
        {
            maxH.push({i.second,i.first});
        }
        string ans="";
        while (maxH.size() > 1) {
            auto top1 = maxH.top(); maxH.pop();
            auto top2 = maxH.top(); maxH.pop();

            ans += top1.second;
            ans += top2.second;

            if (--top1.first > 0){
                maxH.push(top1);
            }
            if (--top2.first > 0){
                maxH.push(top2);
            }
        }

        if (maxH.size()) {
            if (maxH.top().first == 1)
                ans += maxH.top().second;
            else
                return "";
        }
        return ans;
    }
};