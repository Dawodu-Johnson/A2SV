class Solution:
    
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        def swap_it(left:int, right:int) -> None:
            
            if left > right:
                return
            
            else:
                store = s[right]
                s[right] = s[left]
                s[left] = store
                
            return swap_it(left+1, right-1)
        
        swap_it(0, len(s)-1)
        
        
