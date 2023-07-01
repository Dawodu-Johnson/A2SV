#include<bits/stdc++.h>
using namespace std;

int main(){
 int n, m;
 cin >> n >> m;

 vector<vector<int>>graph(n+1);
 int s,dd;
 cin >> s >> dd;

 for(int i = 0; i < m; i++){
     int a, b;
     cin  >> a >> b;

     graph[a].push_back(b); graph[b].push_back(a);
 }

 queue<int>q;
 vector<bool>vis(n+1,false);
 vector<int>parent(n+1),d(n+1,INT_MAX);
 parent[s] = -1;
 d[s] = 0;
 q.push(s);

 while(!q.empty()){

    int node =q.front();
    vis[node] = true;
    q.pop();

    for(int n: graph[node]){
        if(!vis[n]){
            if(d[node]+1 < d[n]){
            parent[n] = node;
            d[n] = d[node]+1;
            q.push(n);
            }
        }
    }
 }

 if(d[dd]==INT_MAX){
    cout << -1 << "\n";
 }
 else {
    cout << d[dd]-d[s] << "\n";
    list<int>store;
    while(dd!=-1){
        store.push_back(dd);
        dd = parent[dd];
    }

    reverse(store.begin(), store.end());
    for(auto&x: store)cout << x << " ";
    cout << endl;
 }
return 0;
}
