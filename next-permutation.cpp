class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int index=-1;
        
        for(int n= nums.size()-1; n >0; --n){
            
            if(nums[n] > nums[n-1]){
                index=n-1;
                break;
            }
        }
        
        // if index ==-1 then all we need is to reverse it rather than sort it.
        
        if(index==-1){
            reverse(nums.begin(), nums.end());
        }
        
        else {
            // find the minimum number greater than 
            int minimum= nums[index];
            int index2=index+1;
            
            for(int i=index+1; i< nums.size(); ++i){
                
               if(nums[i] > minimum && nums[i] <= nums[index2]){
                   index2=i;
               }
            }
            
            swap(nums[index], nums[index2]);
            
            sort(nums.begin()+index+1, nums.end());
            
            // after getting then minimum, then it is time to swap.
            
            
        }
        
        for(const int x: nums) cout << x << " ";
    }
};
