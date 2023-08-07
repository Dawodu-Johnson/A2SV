class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // for a given target => target - nums[i] or 
        
        // dp[0] = 1
        // dp[1] = 1
        // dp[2] += dp[2-1] + dp[2-2]
        // dp[3] += dp[3-1] + dp[3-2] + dp[3-3] = 2 + 1 + 1 = 4
        // dp[4] += dp[4-1] + dp[4-2] + dp[4-3]
        //        =   4 + 2 + 1


        vector<long long>dp(1001, 0ll);
        dp[0] = 1ll;
        
        for(int i = 1; i <= target; i++) {
             for(int value : nums) {
                 if((i-value) < 0)continue;
                 else dp[i] = dp[i] + dp[i-value];
             }
        }
        
        return dp[target];
    }
};
