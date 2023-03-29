#include<bits/stdc++.h>
using namespace std;
 
 
 
void dfs(int parent, vector<vector<int>>&graph, vector<bool>&visited, vector<int>&ans, vector<vector<int>>&answer){
 
    visited[parent] = true;
    ans.push_back(parent);
    for(auto& son: graph[parent]){
 
          if(!visited[son]){
 
            dfs(son, graph, visited,ans,answer);
 
          }
    }
    if(ans.size() >0)answer.push_back(ans);
    ans.clear();
}
int main() {
    // build the tree
    // do a depth first search
    // then do some backtracking and removal of parent nodes.
 
    int t;
    cin >> t;
    while(t--){
 
        int n;
        cin >> n;
        vector<int>store(n);
        for(int&x: store)cin >> x;
        vector<vector<int>>graph(n+1);
        int parent  = 0;
        // 3 1 3 3 1
        for(int i = 0 ; i < store.size(); i++){
              if( i+1 == store[i]){
                 parent = store[i];
 
              }
              graph[store[i]].push_back(i+1);
        }
 
        // now that we have built the tree, it is time to do a depth first search
        vector<bool>visited(n+1,false);
        vector<int>ans;
        vector<vector<int>>answer;
        dfs(parent, graph, visited, ans, answer);
 
        cout << answer.size() << "\n";
 
        for(int i = 0; i < answer.size(); i++){
              cout << answer[i].size() << "\n";
              for(int i : answer[i])cout << i << " ";
              cout << endl;
        }
        cout << endl;
 
    }
    return 0;
}
