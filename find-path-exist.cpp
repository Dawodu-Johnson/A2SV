class Solution {
public:
    struct union_find{
      int n;
      vector<int>parent, rank;
        
      union_find (int n) : n(n) {
          parent.resize(n);
          iota(parent.begin(), parent.end(), 0);
          rank.resize(n,1);
      }
        
      int find(int a){
           if(parent[a] == a)return a;
           return parent[a] = find(parent[a]);
      }
        
      void unite(int a, int b){
           a = find(a), b = find(b);
          
           if(a == b)return;
          
           if(rank[a] < rank[b]){
                parent[a] = b;
                rank[b] += rank[a];
           }
           else{
                parent[b] = a;
                rank[a] += rank[b];
           }
      }
    };
    
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        union_find solve(n);
        
        for(auto& edge : edges){
             if(solve.find(edge[0]) != solve.find(edge[1])){
                  solve.unite(edge[0], edge[1]);
             }
        }
        
        return solve.find(source) == solve.find(destination);
        
    }
};
