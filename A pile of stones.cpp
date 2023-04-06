#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string track;
    int mini = 0, answer = 0;
    char ch;

    for(int i = 0; i < n; i++){

        cin >> ch;
        track+=ch;
        if(ch=='-')--answer;
        else ++answer;

        mini = min(answer, mini);
    }
    mini = abs(mini);
    for(char ch: track){
        if(ch=='-')--mini;
        else ++mini;
    }
    cout << mini << "\n";
    return 0;
}
