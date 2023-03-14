class Solution {
public:
    vector<vector<int>>dp;
    // we can also solve it without caching it by removing the 2d array
    int solve(int i, int j, vector<int>&nums){
        
        if(i > j){
             return 0;
        }
        
        else if(i==j){
             return nums[i];
        }
        
        else if(dp[i][j]!=-1){
            return dp[i][j];
        }
    
        int pick_left = 0, pick_right = 0;
        
        pick_left = nums[i]+ min(solve(i+2, j,nums), solve(i+1, j-1,nums));
        pick_right = nums[j] + min(solve(i,j-2,nums), solve(i+1,j-1,nums));
        
        return dp[i][j] = max(pick_left, pick_right);
    }
    
    
    bool PredictTheWinner(vector<int>& nums) {
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        dp.resize(21, vector<int>(21, -1));
        
        int player1 = solve(0, nums.size()-1, nums);
        
        
        return player1 >=(sum-player1);
    }
};
