class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        // i think this is easy though
        int size = nums.size(), answer = INT_MAX;
        
        vector<long>prefix(size+1);
        prefix[0] = 0;
        
        for(int i = 1; i <=size; i++){
             prefix[i]=prefix[i-1]+nums[i-1];
        }
        
        deque<int>store;
        
        for(int i = 0; i <=size; i++){
            
            //increasing, for the monotonicity
            while(!store.empty() && prefix[store.back()] >= prefix[i]){
                 store.pop_back();
            }
            
            while(!store.empty() && prefix[i]-prefix[store.front()] >=k){
                 answer = min(answer, i-store.front());
                 store.pop_front();
            }
                
            store.push_back(i);
        }
        
        
        return answer ==INT_MAX ? -1: answer;
    }
};
