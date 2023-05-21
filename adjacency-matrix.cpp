#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>>matrix(n, vector<int>(n,0));

    for(int i = 0; i < n; i++){
          int k;
          cin >> k;
          for(int j = 0; j < k; j++){
              int p;
              cin >> p;
              matrix[i][p-1]=1;
          }
    }

    for(int i = 0; i < n; i++){

          for(int j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
          }cout << "\n";

    }
    return 0;
}
