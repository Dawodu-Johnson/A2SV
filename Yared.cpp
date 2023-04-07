#include <bits/stdc++.h>
using namespace std;
 
bool dfs(int a, int b, vector<int>& ans) {
    if (a == b) {
        ans.push_back(a);
        return true;
    }
    if (a > b) {
        return false;
    }
    if (dfs(a*2, b, ans)) {
        ans.push_back(a);
        return true;
    }
    if (dfs(a*10+1, b, ans)) {
        ans.push_back(a);
        return true;
    }
    return false;
}
 
int main() {
 
    int t;
    cin >> t;
 
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        vector<int>bers(n);
        for(int j = 0; j <n; j++){
            cin >> bers[j];
        }
        bool answer = true;
        sort(bers.begin(), bers.end());
        for(int k = 1; k < n; k++){
            if((bers[k]-bers[k-1])>1){
                 answer= false;
                 break;
            }
        }
        if(answer)cout << "YES" <<  "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}
