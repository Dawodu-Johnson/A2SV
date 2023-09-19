class Solution {
public:
    vector<vector<long long>>dp;
    long long mod = 1e9 + 7;
    
    long long solve(int index, int sum, vector<int>&nums) {
        
        if(index == nums.size()) {
            return sum == 0;
        }
        else if(sum < 0)return 0;
        else if(dp[index][sum] != -1) {
            return dp[index][sum];
        }
        long long answer = solve(index + 1, sum, nums);
        
        return dp[index][sum] = (answer + solve(index+1, sum-nums[index], nums))%mod;
    }
    
    long long fast_exponentiation(long long  n, int ex, long long mod) {
       
        if(ex == 0) {
            return 1;
        }
         long long half =  fast_exponentiation(n, ex/2, mod) % mod;
         half = (half * half) % mod;
         if(ex & 1) half = (half * n) % mod;
         return half;
    }
    
    int countPartitions(vector<int>& nums, int k) {

        dp.resize(nums.size()+1, vector<long long>(k+1, -1));
        long long sum = accumulate(nums.begin(), nums.end(), 0ll);
        if(sum < 2*k)return 0;
        sum = 0;
        
        for(int i = 0; i < k; i++) {
            sum = (sum + solve(0, i, nums)) %mod;
        }
        
        return (int)(fast_exponentiation(2ll, nums.size(), mod)-2ll*sum + mod)%mod;
    }
};
