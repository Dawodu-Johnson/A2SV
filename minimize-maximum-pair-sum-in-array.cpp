class Solution {
public:
    int minPairSum(vector<int>& nums) {
        
        // to minimize the sum the it must be the sum of maximum and minimum;
        sort(nums.begin(),nums.end());
        int left = 0, right = nums.size()-1, answer = 0;
        
        
        while(left < right){
            
                answer = max(answer, nums[left]+nums[right]);
                left++;
                right--;
        }
        
        
        return answer;
    }
};
