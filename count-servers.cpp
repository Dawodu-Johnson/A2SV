class Solution {
public:
    
    using T = pair<int, int>;
    
    map<T, T>parent;
    map<T, int>rank;
    
    T find(const T& node){
         if(parent[node] == node)return node;
         return parent[node] = find(parent[node]);
    }
    
    void unite(T a, T b){
        a = find(a);
        b = find(b);
        if(a == b)return;
        
        if(rank[a]  < rank[b]){
             parent[a] = b;
             rank[b]+=rank[a];
             rank[a] = 1;
        }
        else {
             parent[b] = a;
             rank[a] +=rank[b];
             rank[b] = 1;
        }
    }
    
    int countServers(vector<vector<int>>& grid) {
        
        int n = grid.size(), answer = 0, row = grid.size(), col = grid[0].size(); //answer = 0;
        
        for(int i = 0; i < row; i++) {
             
            for(int j = 0; j < col; j++) {
                parent[{i,j}] = {i,j};
                rank[{i,j}] = 1;
            }
        }
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                
                if(grid[i][j] == 1) {
                   
                    for(int p = 0; p < row; p++){
                        if( p != i and grid[p][j] == 1 and find({i,j}) != find({p,j})){
                             unite({i,j}, {p, j});
                        }
                    }
                    
                    for(int k = 0; k < col; k++){
                         if(k != j and grid[i][k] == 1 and find({i,j}) != find({i,k})){
                              unite({i,j}, {i,k});
                         }
                    }
                }
            }
        }
        
        
        for(int i = 0; i < row; i++){
              for(int j =0; j < col; j++){
                   int t = rank[{i,j}];
                  
                   if( t > 1){
                        answer+=t;
                   }
              }
        }
        
        return answer;
    }
};
