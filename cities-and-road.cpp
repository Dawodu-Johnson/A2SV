#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>>graph(n, vector<int>(n,0));

    for(int i = 0; i < n; i++){

         for(int j = 0; j < n; j++){
            cin >> graph[i][j];
         }
    }
    int counter = 0;

    for(int i  = 0; i < n; i++){

         for(int j =0; j < n; j++){
              if(graph[i][j]==1){
                 counter++;
              }
         }
    }
    cout <<  counter/2 << "\n";
    return 0;
}
