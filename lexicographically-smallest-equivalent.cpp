class Solution {
public:
     
     struct union_find{
      int n;
      vector<int>parent, rank;
      vector<set<char>>store;
         
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
                store[b].insert(store[a].begin(), store[a].end());
           }
           else{
                parent[b] = a;
                rank[a] += rank[b];
                store[a].insert(store[b].begin(), store[b].end());
           }
      }
    };
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        union_find sol(27);
        string answer;
        
        for(char x = 'a'; x <='z'; x++){
            sol.store.push_back({x});
        }
        
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]){
                if(sol.find(s1[i]-'a') != sol.find(s2[i]-'a')){
                    sol.unite(s1[i]-'a', s2[i]-'a');
                }
            }    
        }
        
        for(int i = 0;  i < baseStr.size(); i++){
            char c = *sol.store[sol.find(baseStr[i]-'a')].begin();
            if(c <= baseStr[i])answer+=c;
            else answer+= baseStr[i];
        }
        
        return answer;
    }
};
