#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i=n+1; i<9013; i++) {
        int present[10] = {0};
        int year = i;
        int f = 0;
        while(year>0) {
            int r = year%10;
            if(present[r]==1) {
                f = 1;
                break;
            }
            present[r] = 1;
            year = year/10;
        }
        if (f==1)
            continue;
        else
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}