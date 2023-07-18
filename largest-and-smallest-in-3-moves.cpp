class Solution {
public:
    int minDifference(vector<int>& nums) {
        //0,1,5,10,14
        // 1 2, 2 1 , <- 3 , 3 ->
       // [1,5,0,10,14]
        //a, b, c, d, e, f, j, k
        if(nums.size() <=3)return 0;
     
        sort(nums.begin(), nums.end());
        
        return min(min(nums[nums.size()-1]-nums[3],nums[nums.size()-4]-nums[0]), min(nums[nums.size()-2]-nums[2], nums[nums.size()-3]-nums[1]));
        
    }
};
