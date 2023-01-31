class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        for(const auto&x:nums){
            sum+=x;
        }
        unsigned int length=nums.size();
        int prefixsum=0;
        
        for(int i=0; i<length;++i){
            if(sum-prefixsum-nums[i]==prefixsum)return i;
            prefixsum+=nums[i];
        }
        return  -1;
    }
};
