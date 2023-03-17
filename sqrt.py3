class Solution:
    def mySqrt(self, x: int) -> int:
        
        left, right = 1, x
        
        answer  = 0
        while left <= right:
            
            mid = (left+ right)//2;
            
            if mid*mid <= x:
                answer = mid
                left = mid +1
                
            else:
                right = mid -1
                
        return answer
                
