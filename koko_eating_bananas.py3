class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        
        def possible(s:int, h:int, mid:int) ->bool:
            
            total = 0
            
            for value in piles:
                
                if value%mid == 0:
                    total+= value//mid
                else:
                    total+= (value//mid)+1
            
            return total <= h
        
        
#             quotient = 0
            
#             if s%mid == 0:
#                 quotient = s/mid
#             else:
#                 quotient = (s/mid)+1
                
#             return quotient <= h
        
        
        accumulate = sum(piles)
        
        print(accumulate)
        
        left, right = 1, max(piles)
        answer  = 0
        
        
        while left <= right:
            
            mid = left + (right-left)//2
            
            if possible(accumulate, h, mid):
                
                answer = mid
                
                right = mid -1
            else:
                left = mid+1
        
        return answer
    
            
            
            
