//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool answer = false;
    void dfs(int node, vector<vector<int>>&graph, vector<bool>&vis,  int p){
        
        if(answer)return;
        
        vis[node] = true;
       
        
        for(auto& neighbour : graph[node]) {
             
             if(!vis[neighbour]){
                  dfs(neighbour, graph, vis,node);
             }
             else if(vis[neighbour] and p!=neighbour){
                  answer =true;
                  return;
             }
        }
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<vector<int>>graph(V);
        vector<bool>vis(V,false);
      
       for(int i = 0; i < V; i++){
            
             for(int j =0; j < adj[i].size(); j++){
                 
                 graph[i].push_back(adj[i][j]);
             }
       }
       //cout << "okay\n";
        
        for(int i = 0; i < V; i++){
            if(!vis[i] and graph[i].size() > 0){
                 dfs(i, graph, vis,  -1);
                 if(answer == true) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
