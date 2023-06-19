class Solution {
public:
    void sort_data(vector<tuple<int, int, int>>&data){
    
    struct custom_sort{
         
         bool operator()(const tuple<int, int, int>&task1, const tuple<int, int, int>&task2){
         
                if(get<1>(task1) > get<1>(task2) )return true;
                
                else if(get<1>(task1) == get<1>(task2)) return get<2>(task1) > get<2>(task2);
            
                return false; 
         }
    };
    
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<tuple<int, int, int>> data;
        vector<int>answer;
        
        priority_queue< tuple<int, int, int>, vector<tuple<int, int, int>>, custom_sort>process;
        
        
        for(int i = 0; i < tasks.size(); i++){
            data.push_back(make_tuple(tasks[i][0], tasks[i][1], i));
        }
        
        sort(data.begin(), data.end());
       
        int start_time = get<0>(data[0]), index = 0;
        
        while(index < tasks.size()){
         
            int reference = index;
            
            while(index < tasks.size() and get<0>(data[index]) <= start_time) {
                // availability, so we enqueue them.
                process.push(data[index++]);
            }
            
            if(reference == index and process.empty()) {
                // if there is a gap between next to be enqueued and current time
                 start_time = get<0>(data[index]);
                 process.push(data[index++]);
            }
            
            // process.
            if(!process.empty()) {
                start_time = start_time + get<1>(process.top());
                
                answer.push_back( get<2>(process.top()) );
                process.pop();
                
            }
            
        }
        
        while(!process.empty()) {
            answer.push_back( get<2>(process.top()) );
            process.pop();
        }
    
        return answer;
    }
};
