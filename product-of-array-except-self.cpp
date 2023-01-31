class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        unsigned int siz=nums.size();
      
        vector<int>prefix(siz);
        vector<int>suffix(siz);
      
        suffix[siz-1]=1;
        prefix[0]=1;
        vector<int>answer(siz);
      
        for(int i=1; i<siz;++i){  // prefix;
            // calculating the prefixes and the suffixes.
             prefix[i]=nums[i-1]*prefix[i-1];
        }
        
        for(int i=siz-2; i>=0; --i){
            suffix[i]=nums[i+1]*suffix[i+1];
        }
        
        for(int i=0; i<siz;++i){
            answer[i]=prefix[i]*suffix[i];
        }
        return answer;
        
        // initialization done.
        
    }
};
