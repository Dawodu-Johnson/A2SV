class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        
        data =  {};
        
        for w in words:
            
            if w in data:  
                data[w]+=1
            
            else: 
                data[w] = 1
        
        heap = []
        
        for key, value in data.items():
            heapq.heappush(heap, [-value,key])
        
        answer = []
        
        while k > 0:
            answer.append(heap[0][1]);
            heapq.heappop(heap)
            k-=1
        
        return answer
