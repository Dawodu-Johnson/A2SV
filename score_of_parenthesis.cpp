class Solution {
public:
    int scoreOfParentheses(string s) {
        
        int answer = 0;
        
        stack<int>data;
        
        for(const char& ch: s){
            
              if(ch=='('){
                  
                   data.push(answer);
                   answer = 0;
              }
              else{
                   
                   answer = data.top() + max(answer*2, 1);
                   data.pop();
              }
        }
        
        return answer;
        
    }
};
