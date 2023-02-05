class Solution {
public:
    int compress(vector<char>& chars) {
        string store;
        vector<char>input;
        
        int size = chars.size();
        
        for(int i = 0; i < size; i++){
              char start = chars[i];
              int counter = 0;
            
              while(i < size && start==chars[i]){
                   i++;
                   counter++;
              }
              i--;
              input.push_back(start);
              
              if(counter >1){
                     string num = to_string(counter);
                     if(num >="10"){
                           for(const char digit : num){
                                 input.push_back(digit);
                           }
                     }
                     else{
                          input.push_back(counter+'0');
                     }
              }
            
        }
        
        chars = input;
        
        return input.size();
        
    }
};
