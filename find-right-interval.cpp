class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        unordered_map<int, int>indices;
        
        for(int i = 0; i < intervals.size(); i++){
             indices[intervals[i][0]] = i;
        }
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>&a, const vector<int>&b){
             return a[0] < b[0];
        });
   
        
        vector<int>answer(intervals.size(),-1);
        
        
        for(int i = 0; i < intervals.size(); i++){
             
             auto find = lower_bound(intervals.begin(), intervals.end(), vector<int>{intervals[i][1], INT_MIN});
            
             if(find != intervals.end()){
                 answer[indices[intervals[i][0]]] = indices[intervals[find-intervals.begin()][0]];
             }
            
        }
        
        
        return answer;
    }
};
