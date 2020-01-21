#include<bits/stdc++.h>
using namespace std;

long long int prevFib(long long int n) {
    double a = n/((1+sqrt(5))/2);
    return round(a);
}

int main() {
    long long int n;
    cin >> n;
    if (n==0) {
        cout << "0 0 0" << endl;
        return 0;
    } else if (n==1) {
        cout << "1 0 0" << endl;
        return 0;
    } else if (n==2) {
        cout << "1 1 0" << endl;
        return 0;
    } else {
    long long int a = prevFib(n);
    long long int b = prevFib(a);
    long long int c = prevFib(b);
    // int d = prevFib(c);
    cout << b << " " << b << " " << c << endl;
    }
    return 0;
}