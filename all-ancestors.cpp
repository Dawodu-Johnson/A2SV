class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int>inDegree(n,0);
        vector<vector<int>>graph(n);
        vector<set<int>>answer(n);
        queue<int>process;
        
        for(int i = 0; i < edges.size(); i++) {
               graph[edges[i][0]].push_back(edges[i][1]);
               inDegree[edges[i][1]]++;
        }
     
        
        for(int i = 0; i < n; i++) {
            
             if(inDegree[i] == 0) { 
                process.push(i);
             }
        }
        
        
        while(!process.empty()) {
             
            int ancestor = process.front(); process.pop();
            
            for(int neigh:  graph[ancestor]) {
                
                  for(int ances: answer[ancestor]){
                       answer[neigh].insert(ances);
                  }
                  answer[neigh].insert(ancestor);
                
                  if(--inDegree[neigh] == 0) {
                        
                        process.push(neigh);
                  }
            }
        }
        
        vector<vector<int>>result(n);
        
        for(int i = 0; i < n; i++){
              
             for(int p : answer[i]){
                  result[i].push_back(p);
             }
        }
        
        return result;
    }
};
