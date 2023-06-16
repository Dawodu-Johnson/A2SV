class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        
        heap = []
        
        
        for value in nums:
            
            while heap and heap[0][0]+1 < value:
                if heap[0][1] < 3:
                    return False
                heapq.heappop(heap)
                
            if not heap:
                heapq.heappush(heap, [value,1]);
                
            
            elif heap[0][0] == value:
                heapq.heappush(heap, [value,1]);
                
            else:
                freq = heap[0][1]
                heapq.heappop(heap)
                heapq.heappush(heap,[value, freq+1])
            
    
        
        
        while heap:
            if heapq.heappop(heap)[1] < 3:
                return False
        
        return True
    
            
