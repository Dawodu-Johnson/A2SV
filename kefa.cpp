#include<bits/stdc++.h>
using namespace std;
 
int solve(vector<int>&store){
 
  int answer = 1;
 
  // it is continous;
 
  int t = 1;
  for(int i = 1; i < store.size(); i++){
        if(store[i]>=store[i-1]){
                 t++;
        }
        else{
             answer = max(answer, t);
             t = 1;
        }
 
 
  }
 
  answer =max(answer, t);
 
  return answer;
}
 
int main(){
 
int n;
cin >> n;
vector<int>store(n);
for(int i = 0; i < n; i++){
     cin>> store[i];
}
 
cout << solve(store) << "\n";
return 0;}
