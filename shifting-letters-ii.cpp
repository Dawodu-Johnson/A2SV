class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        int length = s.size();
        
        vector<int>answer(s.size(),0);
        
        
        for(const auto& tuple: shifts){
             
             int start = tuple[0], end = tuple[1], value = tuple[2];
             if(value==0)value=-1;  // for backward direction.
             
             answer[start]+=value;
            
             if(end+1 < length){
                  
                  answer[end+1]-=value;
             }
            
        }
        
        partial_sum(answer.begin(),answer.end(),answer.begin());
        
        int increment  = (int)'a';
        
        for(int i =0; i < length; i++){
            
               int val = answer[i]%26;
            
               val = (s[i]-'a' + val + 26)%26;
            
               s[i] = (char)(val+increment);
        }
        
        return s;
        
    }
};
