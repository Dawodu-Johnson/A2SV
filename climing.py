class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)-1
        
        @lru_cache(None)
        def solve(start) -> int:
            
            if start == n:
                return cost[start]
            
            elif start > n:
                return 0
            
            one = cost[start] + solve(start + 1)
            two = cost[start] + solve(start + 2)
            
            return min(one, two)
        
        return min(solve(0), solve(1))
