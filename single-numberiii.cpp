class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int compute = 0, index = 0;
        
        vector<int>answer(2,0);
        
        for(int& x : nums) compute^=x;
        
        for(int i = 0; i <= 31; i++){
              if( (compute >> i) & 1 ){
                    index = i;
                    break;
              }
        }
        
        for(int& x: nums){
            
            if( (x >> index) &1){
                answer[0]^=x;    
            }
            else{
                 answer[1]^=x;
            }
        }
        
        return answer;
    }
};
