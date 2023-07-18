class Solution {
public:
    
    bool pos(int mid, vector<int>&nums){
        long long maxi =  0, num1, nums2;
        
        vector<long long>coppy(nums.begin(), nums.end());
    
        for(int i = nums.size()-1; i > 0; i--){
           if(coppy[i] > mid){
               coppy[i-1]+= (coppy[i]- mid);
           }
           
        }
        maxi = max(coppy[0], (long long)maxi);
        return maxi <= mid;
    }
    
    int minimizeArrayValue(vector<int>& nums) {
        
        int left = 0, right = *max_element(nums.begin(), nums.end()), answer = 0;
     
        while(left <= right){
             int mid = (left + (right-left)/2);
           
             if(pos(mid, nums)){
                 answer = mid;
                 right = mid-1;
             }
             else{
                 left = mid + 1;
             }
        }
        
        return answer;
    }
};
