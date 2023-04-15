class Solution {
public:
    
    
    vector<vector<int>> solve(vector<int>& numbers){
        
        vector<vector<int>>answer= {{}};
        
        // since it might contain duplicates.
        int start=0, end=0, size= numbers.size();
        
        for(int i=0; ai<size; ++i){
              
              start=0;
            
              int n= answer.size();
            
              if(i >0 && numbers[i]==numbers[i-1]){
                  // then there exist duplicates.
                  start= end;
              }
            
              end= n;
              for(int j=start; j <n; ++j){
                  
                 vector<int>temp= answer[j];
                  
                 temp.push_back(numbers[i]);
                 
                  answer.push_back(temp);
              }
         
        }
        
        return answer;
        
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // the array it self might contain duplicates.
        
        // but not the subset.
         
        sort(nums.begin(), nums.end());
        
        vector<vector<int>>ans= solve(nums);
        
        return ans;
    }
};
