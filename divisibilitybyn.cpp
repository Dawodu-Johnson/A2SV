#include<bits/stdc++.h>
using namespace std;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(nullptr);

int t;
cin >> t;
while(t--){

     int n;
     cin >> n;

     vector<int>store(n);
     for(int&x : store)cin >> x;

     int counter = 0;
     for(int x: store){
          int temp = x;
          while(temp %2 == 0){
             temp/=2;
             counter++;
          }
     }

     if(counter >=n){
        cout << 0 << "\n";
     }

     else{

        int answer = 0;
        vector<int>store;

        for(int i = n; i >=2; i--){
             int r = 0;
             int temp = i;

             while(temp%2 == 0){
                temp/=2;
                r++;
             }
             store.push_back(r);
        }

        sort(store.begin(), store.end(), greater<int>());

        for(int i =0; i < store.size(); i++){
            counter+=store[i];
            answer++;
            if(counter >=n){
                break;
            }

        }

        if(counter >=n){
                cout << answer << "\n";
        }

        else{
            cout << -1 << "\n";
        }
     }
}
return 0;
}
