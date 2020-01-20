#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, arr[7];
    cin >> n;
    for(int i=0; i<7; i++)
        cin >> arr[i];

    int flag = 0, day=-1;
    while(true) {
        for(int i=0; i<7; i++) {
            n -= arr[i];
            if(n<=0) {
                flag = 1;
                day = i;
                break;
            }
        }
        if(flag==1)
            break;
    }
    cout << day+1 << endl;
    return 0;
}