class Solution {
public:
    
    int evalRPN(vector<string>& tokens) {
        
        stack<int>data;
        
        for(const string& token : tokens){
            
              // the operators are binary operators which means they require 
            // two operands..
            
            if(token == "+" || token == "*" || token == "/" || token == "-"){
                
                int a = data.top();
                data.pop();
                int b = data.top();
                data.pop();
                
                
                char expression = token.back();
                
                switch(expression){
                    case '+': data.push(a+b);
                        break;
                        
                    case '-': data.push(b-a); 
                        break;
                        
                    case '/': data.push(b/a);
                        break;
                        
                    default: data.push(a*b);
                }
                
            }
            
            else {
          
                  data.push(stoi(token));
            }
        }
        return data.top();
    }
};
