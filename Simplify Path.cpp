class Solution {
public:
    string simplifyPath(string path) {
      stack<string>store;
      vector<string>split_by_slash;
      
      string value;
        
      for(const char& ch: path){
          value+=ch;
          
          if(value[value.size()-1]=='/'){
              
                if(value.size() >1){
                    split_by_slash.push_back(value.substr(0, value.size()-1));
                    split_by_slash.push_back("/");
                }
              
                else{
                    split_by_slash.push_back("/");
                }
              
                value = "";
          }
          
          
      }
      if(value!="")split_by_slash.push_back(value);
        
      for(const string& value: split_by_slash){
        
            if(store.empty()){
                 store.push(value);
            }
            else if(value == ".."){
                  if(store.size() >1){
                       store.pop(); // for slash
                       if(store.size()>1)store.pop(); // for path name
                  }
            }
        
            else if(value == "."){
                 if(store.size()>1)store.pop(); // for the slash
            }
        
            else if(value == "/" && store.top()=="/")continue;
        
            else{
                 store.push(value);
            }
      }
    
    if(store.top()=="/" && store.size()>1)store.pop();
        
    deque<string>answer;
    string ans;
        
    while(!store.empty()){
         answer.push_front(store.top());
         store.pop();
    }
        
    for(const string&val: answer)ans+=val;
    return ans;
      
      
    }
};
