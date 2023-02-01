class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
         
            stack<int>keep_track;
            int size = v.size();
        
            for(int i=0; i < size; i++){
                
                 while(!keep_track.empty() && v[i] > v[keep_track.top()]){
                     
                         v[keep_track.top()]=(i-keep_track.top());
                         keep_track.pop();   
                 }
                
                 keep_track.push(i);
                
            }
                 while(!keep_track.empty()){
                       
                       v[keep_track.top()]=0;
                       keep_track.pop();
                 }
                
        return v;
    }
};
