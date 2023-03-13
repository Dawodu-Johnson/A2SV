class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        stack<int>val;
        long long answer = 0, mod = 1e9+7;
        
        for(int i = 0; i < arr.size(); i++){
            
            while(!val.empty() && arr[i] < arr[val.top()]){
                 // the element to be removed is considered as a pivot where element to be inserted is the right bounday, and the previous element in the stack is the left boundary
              
                 int left = val.top(), value = arr[val.top()], right = i-left-1;
                 val.pop();
                
                 if(!val.empty()){
                      left = (left-val.top()-1);
                 }
                 int window = left+right+1;
                
                 left = (left*(left+1))/2;
                 right = (right*(right+1))/2;
                 window = (window*(window+1))/2;
                 window -=(left+right);
                
                 answer = (answer+ 1ll*(window)*value)%mod;
            }
            
            val.push(i);
        }
        
         while(!val.empty()){
                
                 int left = val.top(), value = arr[val.top()], right = arr.size()-left-1;
                 val.pop();
                
                 if(!val.empty()){
                      left = (left-val.top()-1);
                 }
                 int window = left+right+1;
                
                 left = (left*(left+1))/2;
                 right = (right*(right+1))/2;
                 window = (window*(window+1))/2;
                 window -=(left+right);
                
                 answer = (answer+ 1ll*(window)*value)%mod;
         }
    
        return (int)answer;
    }
};
