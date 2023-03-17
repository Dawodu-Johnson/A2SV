# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        left, right = 1, n
        
        # [true true true bad false false false ]
        OO = n
        
        while left <=right:
            
            mid = (left + right)//2
            
            if not isBadVersion(mid):
                left = mid+1
                
            else:
                OO =  mid
                right = mid -1
                
        return OO
        
            
        
