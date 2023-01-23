class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        bool found = binary_search(nums.begin(), nums.end(), target);
        
        if(!found)return {};
        
        vector<int>answer;
        
        int x = lower_bound(nums.begin(), nums.end(), target)-nums.begin();
        
        while(x < nums.size() && nums[x] == target){
              answer.push_back(x++);
             
        }
        
        return answer;
        
    }
};
