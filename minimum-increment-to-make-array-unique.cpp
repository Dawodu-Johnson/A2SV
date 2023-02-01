class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size(), answer = 0;
        
        
        for(int i = 1; i < size; i++){
            if(nums[i] <= nums[i-1]){
                
                 answer+=abs(nums[i]-nums[i-1])+1;
                 nums[i]+=abs(nums[i]-nums[i-1])+1;
                 
            }
        }
        return answer;
    }
};
