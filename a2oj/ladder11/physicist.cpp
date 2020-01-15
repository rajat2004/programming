// http://codeforces.com/problemset/problem/69/A

#include<iostream>
using namespace std;

int main(){
	int t;
	cin >> t;
	int sum[3]={0, 0, 0};
	int a,b,c;
	while(t--) {
		cin >> a >> b >> c;
		sum[0] += a;
		sum[1] += b;
		sum[2] += c;
	}
	if (sum[0]==0 && sum[1]==0 && sum[2]==0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}