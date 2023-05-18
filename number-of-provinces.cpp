class Solution {
public:
    
    void dfs(int node, vector<bool>&vis, vector<vector<int>>&graph){
        vis[node] = true;
        
        for(auto& ne : graph[node]){
             
             if(!vis[ne]){
                  
                  dfs(ne, vis, graph);
             }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>>graph(isConnected.size());
        
        int n = isConnected[0].size(), answer = 0;
        
        vector<bool>vis(n,false);
        
        for(int i = 0; i < isConnected.size(); i++){
            
            for(int j = 0; j < n; j++){
                
                   if(i != j){
                       
                          if(isConnected[i][j]){
                                
                              graph[i].push_back(j);
                          }
                   }
            }
        }
   
        
        
        for(int i = 0; i < n; i++){
            
            if(!vis[i]){
                answer++;
                dfs(i, vis, graph);
            }
        }
        
        return answer;
        
    }
};
