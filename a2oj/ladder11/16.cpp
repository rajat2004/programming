#include<bits/stdc++.h>
using namespace std;

int main() {
    int k,l,m,n,d;
    cin >> k >> l >> m >> n >> d;
    bool arr[d];
    for(int i=0; i<d; i++)
        arr[i] = false;

    for(int i=k; i<=d; i+=k)
        arr[i-1] = true;
    for(int i=l; i<=d; i+=l)
        arr[i-1] = true;
    for(int i=m; i<=d; i+=m)
        arr[i-1] = true;
    for(int i=n; i<=d; i+=n)
        arr[i-1] = true;

    int count = 0;
    for(int i=0; i<d; i++) {
        if (arr[i] == false)
            count+=1;
    }
    cout << d-count << endl;
    return 0;
}