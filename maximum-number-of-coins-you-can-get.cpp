class Solution {
public:
    int maxCoins(vector<int>& piles) {
        
        deque<int>store;
        
        for(int i: piles)store.push_back(i);
        
        sort(store.begin(),store.end());
        
        int answer =0;
        while(store.size()>=3){
            
            store.pop_front();
            store.pop_back();
            answer+=store.back();
            store.pop_back();
        }
        
        return answer;
        
    }
};
