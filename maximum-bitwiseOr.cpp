class Solution {
public:
    
    map<int, int>store;
    
    void solve(int val, int index, vector<int>&num){
        
        if(index ==  num.size()){
            store[val]++;
            return;
        }
        
        solve(val|num[index], index+1, num);
        
        solve(val, index+1, num);
        
    }
    
    
    int countMaxOrSubsets(vector<int>& nums) {
        solve(0, 0, nums);
        
        if(store.empty())return 0;
        return prev(store.end())->second;   
    }
};
