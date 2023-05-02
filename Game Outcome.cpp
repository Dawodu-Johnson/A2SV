#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
    int n;
    cin >> n;
    vector<vector<int>>cells(n, vector<int>(n,0));
 
    for(int row = 0; row < n; row++){
         for(int col = 0; col  < n; col++){
             cin >> cells[row][col];
         }
    }
    int answer = 0;
 
    vector<int>row(n),col(n);
    for(int i = 0; i < n; i++){
        int sum  = accumulate(cells[i].begin(), cells[i].end(), 0);
        row[i] = sum;
    }
    for(int c = 0; c < n; c++){
         int sum = 0;
         for(int r = 0; r <n; r++){
            sum+=cells[r][c];
         }
         col[c]=sum;
    }
 
 
    for(int r = 0; r < n; r++){
 
         for(int c = 0; c < n; c++){
                if(col[c] > row[r])answer++;
         }
    }
    cout << answer << "\n";
 
    return 0;
}
