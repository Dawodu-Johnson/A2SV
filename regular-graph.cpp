#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>>graph(n);

    for(int i = 0; i < k; i++){

           int x,y;
           cin >> x >> y;
           x--; y--;
           graph[x].push_back(y);
           graph[y].push_back(x);

    }

    int counter = 0, refer = graph[0].size();

    for(int i = 0; i < n; i++){

          if(graph[i].size()==refer)counter++;
    }
    if(counter == n){
         cout << "YES\n";
    }else cout << "NO\n";
    return 0;
}
