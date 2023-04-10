#include <bits/stdc++.h>
using namespace std;
 
 
 
int main(){
 
 
	int l;
	cin >> l;
	long long  maxi = pow(2ll, 32);
	stack<long long> val;
    val.push(1);
 
	long long answer = 0;
 
	for(int i = 0 ; i < l; i++ ){
		string temp;
		cin >> temp;
		if (temp == "for"){
			int x;
			cin >> x;
			val.push(min(maxi, val.top() * x));
		}
		else if (temp == "end"){
			val.pop();
		}
		else{
			answer+= val.top();
		}
	}
 
	if (answer >=maxi)cout << "OVERFLOW!!!" << endl;
	else cout << answer<< endl;
 
		return 0;
}
