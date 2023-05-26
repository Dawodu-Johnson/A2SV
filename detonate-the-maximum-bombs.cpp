class Solution {
public:
    int dfs(int node, vector<vector<int>>&graph, vector<bool>&vis){
       
        int answer = 1, counter = 0;
        vis[node] = true;
    
        for(auto& neigh : graph[node]){
              
                if(!vis[neigh]){
                      counter+=dfs(neigh, graph, vis);
                }
        }
        
        return answer+counter; 
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int n = bombs.size();
        vector<vector<int>>graph(n+1);
        
        for(int i = 0; i < n; i++){
             
                for(int j = 0; j < n; j++){
                    
                     if(i!=j){
                     long long x = bombs[i][0], y = bombs[i][1], r = bombs[i][2];
                     long long m = bombs[j][0], n = bombs[j][1];
                    
                     
                     if( (r*r) >= ((x-m)*(x-m)+ (y-n)*(y-n)) ){
                         graph[i].push_back(j);
                         
                     }
                         
                }
            }
        }
        
     
        int answer =  0;
      
        for(int i = 0; i < n; i++){
             vector<bool>visited(n, false);
             answer = max(answer, dfs(i, graph, visited));
        }
        
        return answer;
    }
};
