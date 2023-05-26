class Solution {
public:
     int dfs(int node, vector<vector<int>>&graphs, vector<bool>&visited){
          int answer = 0;
          visited[node]=true;
        
          for(const auto& neigh: graphs[node]){
              
                if(!visited[neigh]){
                      visited[neigh]=true;
                      answer +=  (1+ dfs(neigh, graphs, visited));
                }
          }
        return answer;
    }
    bool canVisitAllRooms(vector<vector<int>>& edges) {
        int answer = 0;
        int n = edges.size(); 
        
        vector<vector<int>>graphs(n);
        vector<bool>visited(n,false);
        
        for(int i = 0 ; i < n ; i++){
            
                for(const int& value: edges[i]){
                     graphs[i].push_back(value);
                }
        }
        
        answer = dfs(0, graphs, visited) + 1 ;
        if(answer == n)return true;
        return false;
    
    }
};
