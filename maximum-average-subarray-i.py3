class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        
        if len(nums) < k:
            return 0.0
        
        
        add , left, answer = 0, 0, 0
        counter = 0
        
        for i in range(k):
            
            add+=nums[i]
        
        answer = add/k
        x = k
        
        while k < len(nums):
            add-=nums[left]
            add+=nums[k]
            k+=1
            left+=1
            answer = max(answer, add/x)
            
        return answer
