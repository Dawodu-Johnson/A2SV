class Solution {
public:
    string  max_v = to_string(numeric_limits<long long>::max());
    
    bool compare(const string&val){
        
          if(max_v.size() > val.size())return false;
          return max_v < val;
    }
    
    bool solve(int index, string& value, int count, long long first){
        
        
        if(index >= value.size()){
             return count >=2 ?  true: false;
        }
        
        bool answer = false;
        
        for(int i = 1; i <=20; i++){
            
             
             if(index+i <= value.size()){
                 
                 long long number;
                 string store = value.substr(index, i);
                 
                 if(compare(store)){
                     continue;
                 }
                 stringstream ss;
                 ss << store; ss >> number;
                 
                 if(count == 0){
                     answer |= solve(index+i, value, count+1, number);
                 }
                 
                 else if((first-number)==1){  //decreasing.
                      answer |= solve(index+i, value, count+1, number);
                 }
                 
             }
             else {
                  break;
             }
            
        }
        
        return answer;
    }
    
    
    
    bool splitString(string s) {
        
        return solve(0, s, 0, 0ll);
    }
};
