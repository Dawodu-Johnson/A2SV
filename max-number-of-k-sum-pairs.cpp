class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // the answer is how many pairs sum to a give number.
        unordered_multiset<int> store;
        
        int answer=0;
        
        for(const int value: nums){
            if(store.find(k-value)!=store.end()){
               auto temp= store.find(k-value);
                store.erase(temp);
                ++answer;
            }
            else store.insert(value);
        }
        return answer;
    }
};
