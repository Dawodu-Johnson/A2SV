class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        if(arr.size() <3)return 0;
        
        // if we can find the longest increasing subarray for a ending at a particular index and // longest decreasing subsequence starting at a particular array then we should be good to go.
        
        vector<int>increasing(arr.size(),1), decreasing(arr.size(),1);
        
        int size = arr.size();
        
        for(int i =1; i < size; i++){
             // for increasing
             if(arr[i] > arr[i-1]){
                  increasing[i]=increasing[i-1]+1;
             }
        }
    
        
        for(int i = size-1; i >0; i--){
            
            // for decreasing 
            
            if(arr[i] < arr[i-1]){
                 decreasing[i-1] = decreasing[i]+1;
            }
        }
        
        // we could have merged both for loops as one but we need clarity here...
        
        int answer = 0;
        
        for(int i = 0 ; i < size; i++){
            
               if(increasing[i] >1 && decreasing[i] >1)
                   answer = max(answer, increasing[i]+decreasing[i]-1);
        }
        
        return answer>=3 ? answer : 0;
        
        
        
    }
};
