class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
 
        for i in range(1,n):
            
            for row in range(len(triangle[i])):
                left , right = 10**5, 10**5
                if row-1 >= 0:
                    left = triangle[i-1][row-1]
                if row < len(triangle[i-1]):
                    right = triangle[i-1][row]
                triangle[i][row] = triangle[i][row] + min(left, right)
        
        
        return min(triangle[n-1])
                
                
                    
        
        
