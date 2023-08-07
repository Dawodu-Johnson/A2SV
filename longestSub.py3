class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        dp = {}
       
        for val in arr:
            if dp.get(val-difference,-1) == -1:
                dp[val] = 1
            else:
                dp[val] = dp[val-difference] + 1
        return max(dp.values())
