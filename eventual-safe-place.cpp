class Solution {
public:
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        vector<int>inD(graph.size(),0);
        vector<vector<int>>redirect(graph.size());
        queue<int>process;
        
        for(int i = 0; i < graph.size(); i++){
            
             for(int neigh: graph[i]){
                   redirect[neigh].push_back(i);
                   inD[i]++;
             }
        }
        
        for(int i = 0; i < n; i++){
            if(inD[i] == 0) process.push(i);   
        }
        
        vector<int>answer;
        
        while(!process.empty()){
              int t = process.front();  process.pop(); answer.push_back(t);
              for(int neigh: redirect[t]){
                     if(--inD[neigh]==0){
                            process.push(neigh);
                     }
              }
        }
        
        sort(answer.begin(), answer.end());
        
        return answer;
        
    }
};
