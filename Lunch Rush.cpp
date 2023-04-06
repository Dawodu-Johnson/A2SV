#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, f, t, answer = INT_MIN;
    cin >> n >> k;

    for(int  i = 0; i < n; i++){
        cin >> f >> t;

        if(t > k){
             answer = max(answer, f-(t-k));
        }
        else{
             answer = max(answer, f);
        }
    }

    cout << answer << "\n";

    return 0;
}
