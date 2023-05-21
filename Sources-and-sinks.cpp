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
    vector<int>sink, source;

    for(int  i = 0; i < n; i++){

          int counter = 0;

          for(int j = 0; j < n ; j++){

                if(matrix[i][j] == 0){
                    counter++;
                }
          }
          if(counter == n)sink.push_back(i+1);
    }

    for(int i = 0; i < n; i++){

          int counter = 0;

          for(int j = 0; j < n; j++){

             if(matrix[j][i]==1){
                 counter++;
             }
          }

          if(counter ==0) source.push_back(i+1);
    }

    cout << source.size() << " ";
    for(int x: source)cout << x << " ";
    if(source.size())cout << "\n";

    cout << sink.size() << " ";
    for(int x: sink)cout << x << " ";
    if(sink.size())cout << "\n";
    return 0;
}
