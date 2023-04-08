class Solution {
public:
    
    bool solve(int index, string &nums, int numbers, long long first, long long second){
        
        bool answer = false;
        
        if(index >= nums.size()){
          
          return numbers>=3 ? true: false;
               
        }
        
         
        for(int i = 1; i <= 17; i++){    // use 17 as max length for a given integer because floor(35/2)
            // we can pick the first i numbers for kth index.
            if(index + i <=nums.size()){
                
                string store = nums.substr(index, i);
                
                 if(store.size() >1 && store[0]=='0'){  // leading zeros
                    continue;
                 }
                
                long long value;
                stringstream ss;
                ss << store;
                ss >> value;
                
                if(numbers <=1){
                     if(numbers == 0) answer|=solve(index+i, nums, numbers+1, value, second);
                     else  answer|=solve(index+i, nums, numbers+1, first, value);
                }
                
                else{
                    
                    
                     if(first+second == value){
                         answer|=solve(index+i, nums, numbers+1, second, value);
                     }
                }
                
            }
            
            else{
                 break;
            }
        }
        
        return answer;
        
        
    }
    
    
    bool isAdditiveNumber(string num) {
        
        if(num.size() <3)return false;
        
        return solve(0,num,0, 0ll, 0ll);
    }
};
