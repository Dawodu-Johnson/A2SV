class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int, int>data;
        for(const int& val: nums){
             data[val]++;
        }
        
        int answer =0;
        
        for(const auto& val : data){
            
              answer+= (val.second* (val.second-1))/2;
        }
        
        
        return answer;
    }
};
