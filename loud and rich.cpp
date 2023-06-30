class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>>graph(n);
        vector<int>indegree(n,0);
        vector<int>answer(n,-1);
        queue<int>process;
        
        for(int i = 0; i < richer.size(); i++){
             graph[richer[i][0]].push_back(richer[i][1]);
             indegree[richer[i][1]]++;
        }
        
        
        for(int i = 0; i < n; i++){
              if(indegree[i] == 0){
                    process.push(i);
              }
        }
        
        for(int i = 0; i < n; i++){
             answer[i] = i;
        }
        
        while(!process.empty()){
            
             int ancestor = process.front(); process.pop();
            
             for(auto& children : graph[ancestor]){
               
                 
                  if(quiet[answer[children]] > quiet[answer[ancestor]] ){
                      answer[children] =  answer[ancestor];
                  }
                 
                  if(--indegree[children] == 0){
                      process.push(children);
                  }
             }
        }
        
        
        
        return answer;
    }
};
