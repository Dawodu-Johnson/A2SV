class Solution {
public:
    string compute(const string& value, int k){
        string answer;
        
        for(int i = 0; i < k; i++){
             answer+=value;
        }
        
        return answer;
    }
    
    string decodeString(string s) {
        //number[expression]
        int size = s.size();
        stack<char>data;
        
        for(int i = 0; i < size; i++){
       
            
            if(s[i]!=']'){
                data.push(s[i]);
            }
            
            else{
                //we have encountered a ]
                
                string characters;
                int k = 0;
                
                while(!data.empty() && data.top()!='['){
                    characters+=data.top();
                    data.pop();
                }
               
                if(!data.empty()){  // [
                    data.pop();
                }
                //cb
                reverse(characters.begin(), characters.end());
                string integers;
                
                while(!data.empty() && isdigit(data.top())){
                    integers+=data.top();
                    data.pop();
                }
               
                reverse(integers.begin(), integers.end());
                string answer = compute(characters, stoi(integers));
            
                for(const char & ch: answer){
                     data.push(ch);
                }
                
            }
        }
        
        string final_answer;
        
        while(!data.empty()){
              final_answer+=data.top();
              data.pop();
        }
        reverse(final_answer.begin(), final_answer.end());
        
        return final_answer;
        
    }
};
