#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>>graph(n);
    int k;
    cin >> k;

    for(int i = 0; i < k; i++){

           int l;
           cin >> l;

           if(l ==1){
                int o,p;
                cin >> o >> p;
                o--;p--;
                graph[o].push_back(p);
                graph[p].push_back(o);
           }
           else{
                int o;
                cin >> o; o--;
                for(int &l: graph[o]){
                    cout << l+1 << " ";
                }if(graph[o].size())cout << "\n";
           }

    }
    return 0;
}
