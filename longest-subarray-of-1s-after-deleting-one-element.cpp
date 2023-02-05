class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // this is the same as longest subarray containing at most one one. -1;
        
        int length=0;
        int size= nums.size();
        int counter=0;
        
        for(int low=0,high=0; high <size; high ++){
            
           if(nums[high]==0)++counter;
            
           if(counter >1){
               
               while(nums[low]){
                   ++low;
               }
               low++;
               counter-=1;
           }
            
          length= max(length, high-low);
        }
        
        return length;
    }
};
