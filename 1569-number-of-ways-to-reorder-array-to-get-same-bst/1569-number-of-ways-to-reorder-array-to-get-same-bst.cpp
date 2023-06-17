class Solution {
public:
    
    int mod = 1e9 + 7;
    long long dp[1001][1001] = {};
    
    int helper(vector<int> & nums){
        if(nums.size() <= 2)
            return 1;
        
        int n = nums.size(); 
        vector<int> left, right;
        for(int i = 1; i<n; i++){
            if(nums[i] < nums[0])
                left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        
        int leftAns = helper(left), rightAns = helper(right);
                
        return (((dp[n-1][left.size()] * leftAns)%mod) * rightAns)%mod;
    
    }
    
    
    int numOfWays(vector<int>& nums) {
        for(int n = 0; n <= 1000; n++){
            dp[n][0] = 1;
        }
        for(int n = 1; n <= 1000; n++){
            for(int r = 1; r <= n; r++){
				// nCr = n-1Cr-1 + n-1Cr
                dp[n][r] = (dp[n-1][r-1] + dp[n-1][r])%mod;
            }
        }
        
        int res = (helper(nums) - 1 + mod)%mod;
        
        return res;
    }
};