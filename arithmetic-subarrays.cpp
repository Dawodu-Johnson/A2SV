class Solution {
public:
    bool check(vector<int>&val){
        
        int size = val.size();
        if(size ==1)return true;
        int diff = val[1]-val[0];
        
        for(int start = 2; start <size; start++){
             if( (val[start]-val[start-1])!=diff)return false;
        }
        
        return true;
    }
    
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        int size = l.size();
        
        vector<bool>answer;
        
        for(int i = 0; i < size; i++){
            vector<int>temp(nums.begin()+l[i], nums.begin()+r[i]+1);
            
            sort(temp.begin(), temp.end());
            
            
            if(check(temp)){
                 answer.push_back(true);
            }
            else answer.push_back(false);
        }
        
        return answer;
        
    }
};
