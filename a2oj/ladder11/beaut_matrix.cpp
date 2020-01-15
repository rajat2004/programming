// http://codeforces.com/problemset/problem/263/A
#include <bits/stdc++.h>
using namespace std;

int main(){
	int i,j,a;
	int m,n;
	for(i=0; i<5; i++) {
		for(j=0;j<5;j++) {
			cin >> a;
			if (a!=0){
				m = i;
				n=j;
			}
		}
	}
	cout << abs(m-2) + abs(n-2) << endl;
	return 0;
}