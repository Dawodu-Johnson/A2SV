class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>&visited){
         visited[node]=true;
         
        for(const auto & val: adj[node]){
             if(!visited[val]){
                 visited[val]=true;
                 dfs(val,adj,visited);
             }
        }
        
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        
        vector<vector<int>>adj(n);
        vector<bool>visited(n,false);
        int size=edges.size();
        
        for(int i=0; i<size;++i){
               adj[edges[i][0]].push_back(edges[i][1]);
               adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(start,adj,visited);
        if(visited[end]==false)return false;
        return true;
        // now you want to check if a path exist.
    }
};
