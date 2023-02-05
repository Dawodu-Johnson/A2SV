class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       
        
        // maintain the invariant that if you find a non-zero element,
        // if there exist a zero before it, swap it
        
        int size= nums.size();
        
        for(int high=0,low=0; high< size; high++){
            
            if(nums[high]!=0){
                
                while(low < high){
                    if(nums[low]==0){
                        swap(nums[low],nums[high]);
                        ++low;
                        break;
                    }
                    ++low;
                }
            }
           
        }
    }
};
