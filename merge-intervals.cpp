class Solution {
public:
    
    bool check(const vector<int>&first, const vector<int>&second){
        
           if(second[0] >=first[0] && second[0] <=first[1]){
                return true;
           }
        
        return false;
        
    }
    
    vector<int> merge(const vector<int>&first, const vector<int>&second){
        
           return {min(first[0],second[0]), max(second[1],first[1])};
        
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int size = intervals.size();
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>>answer;
        int pointer = 0;
        
        for(int i = 0; i < size; i++){
            
              vector<int>curr = intervals[i];
            
              while(i < size && check(curr, intervals[i])){
                   curr = merge(curr, intervals[i]);
                   i++;
              }
            
              answer.push_back(curr);
              i--;
        }
        
        return answer;
        
    }
};
