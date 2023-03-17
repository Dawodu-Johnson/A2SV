class Solution {
public:
    int solve(const string&val){
         
         vector<int>store(26,0);
        
         for(const char& v: val){
              store[v-'a']++;
         }
        
         int answer = 0;
        
         for(int i = 0; i < 26; i++){
              
               if(store[i] >0)return store[i];
         }
        
        return answer;
        
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        
        vector<int>storeQueries,bounds,answer;
        
        for(const auto& val : queries){
             storeQueries.push_back(solve(val));
        }
        
        for(const auto& val : words){
             bounds.push_back(solve(val));
        }
        
        sort(bounds.begin(), bounds.end());
        
        for(int i = 0; i < storeQueries.size(); i++){
            // find the first number greater than it in bounds.
             auto f = upper_bound(bounds.begin(), bounds.end(), storeQueries[i]);
             if(f!=bounds.end()){
                   answer.push_back(bounds.size()-(f-bounds.begin()));
             }
             else{
                  answer.push_back(0);
             }
        }
        
        return answer;
        
    }
};
