class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int length=numeric_limits<int>::max(), size= nums.size();
        int sum=0;
        
        
        for(int low=0, high=0; high < size; high++){
            
            sum+= nums[high];
            
            while(sum >= target){
                
                length=  min(length, high-low+1);
                sum-=nums[low];
                ++low;
            }
        }
        
        
        return length==numeric_limits<int>::max() ? 0 : length;
    }
};
