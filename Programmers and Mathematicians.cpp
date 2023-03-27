#include<bits/stdc++.h>
using namespace std;

bool possible(long long a, long long b, long long k){
   if((a-k)<0 || (b-k)<0){
     return false;
   }
   a-=k;
   b-=k;
   if((a+b)>=2*k)return true;
   return false;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    long long a, b;
    while(t--){
        cin >> a >> b;
        long long left = 0, right = max(a,b), answer = 0;

        while(left <= right){

             long long mid = (left)+ (right-left)/2;

             if(possible(a,b, mid)){
                  answer = mid;
                  left = mid+1;
             }
             else{
                 right = mid - 1;
             }
        }
        cout << answer << "\n";
    }

    return 0;
}
