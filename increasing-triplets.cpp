class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
          vector<int>maintain;
        
          for(int & val : nums){
                 
                 auto f= lower_bound(maintain.begin(), maintain.end(), val);
              
                if(f==maintain.end()){
                       maintain.push_back(val);
                      if(maintain.size()==3)return true;
                }
              
                 else if(*f > val){
                    *f=val;
                 }
          }
        
        return false;
    }
};
