class Solution {
public:
    
    vector<int>rank, parent;
    int redundants = 0;
    
    int find(int node){
         if(parent[node] == node)return node;
         return parent[node] = find(parent[node]);
    }
    
    void unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b){
            return;
        }
        
        else if(rank[a]  < rank[b]){
             parent[a] = b;
             rank[b]+=rank[a];
        }
        else {
             parent[b] = a;
             rank[a] +=rank[b];
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        rank.resize(edges.size()+1, 1); parent.resize(edges.size()+1);
        
        for(int i = 1; i <= edges.size(); i++)parent[i] = i;
        
        for(auto edge : edges){
              if(find(edge[0])!=find(edge[1])){
                  unite(edge[0], edge[1]);
              }
              else return edge;
        }
        return {};
    }
};
