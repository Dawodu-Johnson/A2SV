class Solution {
public:
    vector<vector<int>>ans;
    void dfs(int start, int end, vector<bool>&visited,
             vector<int>&answer, vector<vector<int>>&graphs){
        
        answer.push_back(start);
        visited[start]=true;
        if(start == end){
            ans.push_back(answer);   
            return;
        }
        for(const auto& neigh: graphs[start]){
            
             if(!visited[neigh]){
                   visited[neigh]= true;
                   dfs(neigh, end, visited, answer, graphs);
                   answer.pop_back();
                   visited[neigh]=false;
             }
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
       // first of all, let us build the graph.
        
      vector<vector<int>>graphs(graph.size());
        
      int size = graph.size();
        
        
      for(int i = 0; i < size; i++){
           
           for(const auto& element: graph[i]){
                graphs[i].push_back(element);
           }
      }
      vector<bool>visited(graph.size(), false);
        
      int start = 0, end = graph.size()-1;
      vector<int>answer;
       dfs(start,end,visited,answer, graphs);
      return ans;
      // so we have built the graph, now it is time to do the dfs.
        
      
    }
};
