class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int answer=0,size=s.size();
        
        map<char, int>store;
        
        int counter=0;
        
        
        for(int high=0,low=0; high <size; high++){  // size of s
             
            store[s[high]]++;
            
            if(store[s[high]]> 1){
                
                while(s[low]!=s[high]){ store[s[low]]--; low++;}   
                store[s[low]]--;
                low++;
            }
                 counter= max(counter,high-low+1);
        
        }
        
        return counter;
    }
};
