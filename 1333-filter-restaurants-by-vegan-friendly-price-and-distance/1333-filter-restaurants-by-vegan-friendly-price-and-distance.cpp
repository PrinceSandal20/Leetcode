class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        priority_queue<pair<int,int>>maxH;
        for(int i=0;i<restaurants.size();i++)
        {
            if(veganFriendly==1){
                if(restaurants[i][2]==veganFriendly && restaurants[i][3]<=maxPrice && restaurants[i][4]<=maxDistance)
                {
                    maxH.push({restaurants[i][1],restaurants[i][0]});
                }
            }
            else if(veganFriendly==0){
                if(restaurants[i][3]<=maxPrice && restaurants[i][4]<=maxDistance)
                {
                    maxH.push({restaurants[i][1],restaurants[i][0]});
                }
            }
        }
        vector<int>ans;
        while(!maxH.empty()){
            ans.push_back(maxH.top().second);
            maxH.pop();
        }
        return ans;
    }
};