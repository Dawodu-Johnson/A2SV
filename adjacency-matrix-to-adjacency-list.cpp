#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>>matrix(n, vector<int>(n,0));

    for(int i = 0; i < n; i++){

          for(int j = 0; j < n; j++){
              cin >> matrix[i][j];
          }
    }

    for(int i = 0; i < n; i++){

          int counter = 0;

          for(int j = 0; j < n; j++){

               if(matrix[i][j]==1){
                 counter++;
               }
          }

          cout << counter << " ";

          for(int j = 0; j < n; j++){

              if(matrix[i][j]){
                  cout << j+1 << " ";
              }

          }

          if(counter)cout << "\n";

    }
    return 0;
}
