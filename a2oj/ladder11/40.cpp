#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,a;
    cin >> n;
    int count_5=0, count_0=0;
    for(int i=0; i<n; i++) {
        cin >> a;
        if(a==5)
            count_5+=1;
        else 
            count_0+=1;
    }
    if (count_0 == 0) {
        cout << -1 << endl;
        return 0;
    }
    if(count_5>=9) {
    for(int i=0; i<(count_5/9); i++)
        cout << "555555555";
    for(int i=0; i<count_0-1; i++)
        cout << "0";
    }
    cout << "0" << endl;
    return 0;
}