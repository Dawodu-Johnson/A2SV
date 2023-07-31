class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        
        
        dp = {}
        
        def recursion(start_x, start_y):
            
            if start_x > m or start_y > n:
                return 0
            elif (start_x, start_y) in dp:
                return dp[(start_x, start_y)]
            elif  start_x == m and start_y == n:
                return 1
            
            right , down = 0 , 0
          
            down = recursion(start_x+1, start_y)
            right = recursion(start_x, start_y+1)
            
            dp[(start_x, start_y)] = down + right
            return dp[(start_x, start_y)]
        
        return recursion(1,1)
