class KthLargest {
  
    int size;
    priority_queue<int,vector<int>,greater<int>>store;
  
public:
  
    KthLargest(int k, vector<int>& nums) {
      
        size=k;
      
        for(const int &value: nums)store.push(value);
        
        while(store.size() > size){
            store.pop();
        }
      
    }
    
    int add(int val) {
        
        store.push(val);
      
        if(store.size() >size){
            store.pop();
        }
        
        return store.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
