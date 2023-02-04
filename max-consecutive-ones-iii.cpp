class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // we want to maintain a subarray having at most k flips.
        
        int size= nums.size();
        int window=0;
        int length=0;
    
        
        for(int low=0, high=0; high < size; high++){
            
            if(nums[high]==0)++window;
            
            if(window >k)
            {
                while(nums[low]){
                
                 low++;
            }
                low++;
                window-=1;
                
            }
            
            length= max(high-low+1, length);
        }
        
        return length;
        
    }
};
