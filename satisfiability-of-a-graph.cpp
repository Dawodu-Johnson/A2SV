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
    bool equationsPossible(vector<string>& equations) {
        // equal to simply means same group ..
        parent.resize(27);
        rank.resize(27, 1);
        iota(parent.begin(), parent.end(), 0);
        
        for(int i = 0; i < equations.size(); i++){
            if(equations[i][1] == '='){
                unite(equations[i][0]-'a', equations[i][3]-'a');
            }
        }
        
        for(int i = 0; i < equations.size(); i++){
             if(equations[i][1] == '!' and find(equations[i][0]-'a') == find(equations[i][3]-'a')){
                return false;
             }
        }
        
        return true;
    }
};
