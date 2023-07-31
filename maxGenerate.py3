class Solution:
    def getMaximumGenerated(self, n: int) -> int:
        if n  <= 0:
            return 0
        
        store = [0 for _ in range(n+1) ]
        store[0] = 0
        store[1] = 1
        
        for i in range(1, n+1):
            if 2*i <= n:
                store[2*i] = store[i]
               
            if 2*i + 1 <= n:
                store[2*i + 1] = store[i+1] + store[i]
  
        return max(store)
        
