#include<bits/stdc++.h>
using namespace std;
 
 
int answer = INT_MAX;
 
void solve(int n, long long q, int cal){
  if(n >q)return;
  else if(n == q){
     answer = min(answer, cal);
     return;
  }
  else{
      solve(n*2, q, cal+1);
      solve(n*3, q, cal+1);
  }
}
 
int main(){
/*
int q;
cin >> q;
 
for(int i = 0; i < q; i++){
     int n;
     cin >> n;
     n*=4;
     unordered_map<int, int>sides;
     int k;
     bool check  = false;
     for(int j = 0; j < n; j++){
         sides[k]++;
         if( (sides[k]/4)>=n){
             check = true;break;
         }
     }
     if(check){
 
     }
     else{
 
     for(auto& val : sides){
 
     }
 
     }
}*/
int n, q;
 
bool no  = false;
cin >> n >> q;
solve(n, q, 0);
if(answer!=INT_MAX) cout << answer << "\n";
else cout << -1 << "\n";
return 0;}
