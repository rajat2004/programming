#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,a;
    cin >> n;
    int sum = 0;
    for(int i=0; i<n; i++) {
        cin >> a;
        sum += a;
    }
    int count = 0;
    for(int i=1; i<6; i++) {
        if((sum+i)%(n+1) != 1)
            count+=1;
    }
    cout << count << endl;
    return 0;
}