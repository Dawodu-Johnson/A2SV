/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int dfs(vector<vector<int>>&adj, vector<bool>&visited, int id, map<int,int>&v){
           int value =0;
        
           visited[id]=true;
           
           for(int neigh : adj[id]){
               
                  if(!visited[neigh]){
                        
                         value +=dfs(adj, visited, neigh, v);
                  }
           }
        return v[id]+value;
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        
        // okay this is basically a depth first search on the id 
        // i need to create a graph based on the ids.
        vector<vector<int>>adj(2001);
        map<int,int>importa;
        int size = employees.size();
        
        for(int i=0; i < size; i++){
                  importa[employees[i]->id]= employees[i]->importance;
                  //adj[employees[i]->id].push_back(employees[i]->subordinates);
                  for(int val : employees[i]->subordinates){
                      
                         adj[employees[i]->id].push_back(val);
                  }
            
        }
        
        // at the end of the day we have our graph ready for transversal
        
        vector<bool>visited(2001, false);
        
        int answer = dfs(adj,visited,id,importa);
        return answer;
        
    }
};
