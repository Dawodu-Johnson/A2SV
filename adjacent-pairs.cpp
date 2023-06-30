class Solution {
public:
    vector<int>answer;
    
    void dfs(int node, unordered_set<int>&vis,unordered_map<int, vector<int>>&graph){
        
        vis.insert(node);
        answer.push_back(node);
        for(auto& neigh : graph[node]){
             if(vis.find(neigh)== vis.end()){
                  dfs(neigh, vis, graph);
             }
        }
    }
    
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        // this looks like topological sorting .
        
   
        unordered_map<int, vector<int>>graph;
        unordered_map<int, int>ind;
        unordered_set<int>vis;
        
        for(int i = 0; i < adjacentPairs.size(); i++){
             graph[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
             graph[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
             ind[adjacentPairs[i][0]]++;
             ind[adjacentPairs[i][1]]++;
        }
        
        for(auto& d: ind){
             if(d.second == 1){
                  dfs(d.first, vis, graph);
                  break;
             }
        }
       
        
        return answer;
    }
};
