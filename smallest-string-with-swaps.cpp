class Solution {
public:
     struct union_find{
      int n;
      vector<int>parent, rank;
      unordered_map<int, multiset<char>>store;
         
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
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        union_find solve(s.size());
        string answer;
        
        for(int i = 0; i < s.size(); i++){
            solve.store[i].insert(s[i]);
        }
        
        for(auto& pair : pairs){
             solve.unite(pair[0], pair[1]);
        }
       // cout << "yo\n";
        for(int i = 0; i < s.size(); i++){
             int rep = solve.find(i);
             char p = *solve.store[rep].begin();
             answer+=p;
             solve.store[rep].erase(solve.store[rep].begin());
        }
        
        return answer;
    }
};
