class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        #so running sum is simply prefix sum
        size=len(nums)
        for val in range(size):
            
            if val==0:
                continue
            else:
                nums[val]+=nums[val-1]
        
        return nums
