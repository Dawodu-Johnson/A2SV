class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>store;
        
        for(int x: nums) store.push(x);
        
        while(k>1){
            store.pop();
            --k;
        }

        return store.top();
    }
};
