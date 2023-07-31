class Solution {
public:
     
 int solve(vector<int>&nums, int index, int size, vector<int>&dp){
        // at the end of the day we can either rob u or not
         
         if(index >=size)return 0;
        
         if(dp[index]!=-1) return dp[index];
         int dontrob = solve(nums, index+1, size, dp), rob = 0;  
        
         rob = nums[index]+ solve(nums, index+2, size, dp);
         return dp[index]= max(rob,dontrob); 
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        
        vector<int>dp(nums.size(), -1), dp1(nums.size(), -1);
        
        // if we are going to have a possibility where we rob 0, 
        // then we should not include n as a possibility
        
        return max(solve(nums, 0, nums.size()-1, dp), solve(nums,1, nums.size(),dp1));
    }
};
