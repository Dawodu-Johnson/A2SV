

Codeforces
| In English По-русски
beejaydj22 | Logout
 You have +148! Wow!

HOMETOPCATALOGCONTESTSGYMPROBLEMSETGROUPSRATINGEDUAPICALENDARHELP


PROBLEMSSUBMIT CODEMY SUBMISSIONSSTATUSHACKSSTANDINGSCUSTOM INVOCATION
    
General
  
#	Author	Problem	Lang	Verdict	Time	Memory	Sent	Judged	 	 
199752903	Practice:
beejaydj22	1675D - 23	GNU C++17	Accepted	904 ms	23900 KB	2023-03-29 23:17:25	2023-03-29 23:17:25	Add to favourites	Compare
→ SourceCopy
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
Click to see test details

Codeforces (c) Copyright 2010-2023 Mike Mirzayanov
The only programming contests Web 2.0 platform
Server time: May/10/2023 12:36:36UTC+1 (i1).
Desktop version, switch to mobile version.
Privacy Policy
Supported by
TON ИТМО
