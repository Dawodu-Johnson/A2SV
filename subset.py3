class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        
        answer, bucket , size = [], [], len(nums)
        
        
        def recurse(i, bucket):
            
            if i == size:
                answer.append(bucket.copy())
            
            
            else:
                
                bucket.append(nums[i])
                recurse(i+1, bucket)
                bucket.pop()
                recurse(i+1, bucket)
        
        recurse(0, bucket)
        return answer
