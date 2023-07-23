class Solution {
public:
    int minMoves(vector<int>& nums) {
        return accumulate(begin(nums),end(nums),0) - ((int)nums.size() * (int)*min_element(begin(nums),end(nums)));
    }
};