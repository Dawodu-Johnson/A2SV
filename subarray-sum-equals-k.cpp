class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
         int total=0;
         int sum=0;
         unordered_map<int,int>store;
        for(const int &val:nums){
            sum+=val;
            if(sum==k)++total;
            if(store.find(sum-k)!=store.end()){
                total+=store[sum-k];
            }
           ++store[sum];
        }
        return total;
    }
    
};
