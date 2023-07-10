class Solution {
public:
    
    struct union_find{
      int n, total;
      vector<int>parent, rank;
      
      union_find (int n) : n(n) {
          parent.resize(n);
          iota(parent.begin(), parent.end(), 0);
          rank.resize(n,1);
          total = n;
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
           total-=1;
      }
    };
    
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size(); 
        union_find solve(n);
        
        for(int i = 0; i < n; i++){
              for(int j = i; j < n; j++){
                    if(stones[i][0] == stones[j][0] or (stones[i][1] == stones[j][1])){
                         solve.unite(i, j);
                    }
              }
        }
        
        return n - solve.total;
    }
};
