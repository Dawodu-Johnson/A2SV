#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, d;
  cin >> n >> d;
  vector<int>p(n);
  for(int &x: p)cin >> x;
  sort(p.begin(), p.end(), greater<int>());
  int answer = 0, total = 0;
  for(int i = 0; i < p.size(); i++){
     int k = 0;
 
     k = (d/p[i]) + 1;
     if(k+total <= p.size()){
        ++answer;
        total+=k;
     }
     else break;
  }
  cout << answer << "\n";
 
  return 0;
}
