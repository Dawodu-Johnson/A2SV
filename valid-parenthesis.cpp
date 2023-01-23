class Solution {
public:
    bool isValid(string s) {
        stack<char>ch;
        stringstream ss; 
        ss << s;
        char x;
        
        while(ss>> x){
            if(x=='(' || x=='[' || x=='{'){
             ch.push(x); 
        }
            else {
                if(ch.empty())return false;
                
                else if(x==']' && ch.top()=='[')ch.pop();
                else if(x==')' && ch.top()=='(')ch.pop();
                else if(x=='}' && ch.top()=='{')ch.pop();
                
                else return false;

            }
    }
        if(ch.size())return false;
        return true;
    }
};
