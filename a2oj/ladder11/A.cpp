// http://codeforces.com/contest/1294/problem/A

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long int a,b,c,n;
        cin >> a >> b >> c >> n;
        // long long int A = (n+c+b - 2*a)/3;
        // long long int B = (n+a+c - 2*b)/3;
        // long long int C = (n+a+b - 2*c)/3;
        // if( (a+A)==(b+B) && (b+B)==(c+C) && (A+B+C)==n)
        long long int k = n+a+b+c;
        if ((n+a+b+c)%3 != 0)
            cout << "NO" << endl;
        else {
            long long int l = k/3;
            if((l-a)>=0 && (l-b)>=0 && (l-c)>=0)
                cout << "YES" << endl;
            else 
                cout << "NO" << endl;
        }
    }
    return 0;
}