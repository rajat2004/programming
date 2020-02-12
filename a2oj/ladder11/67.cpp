#include<bits/stdc++.h>
using namespace std;

void err() {
    cout << -1 << endl;
}

int main() {
    int c[8]={0};
    int n,a;
    cin >> n;
    string s;
    for(int i=0; i<n; i++) {
        cin >> a;
        c[a]++;
    }
    if(c[5]!=0 || c[7]!=0) {
        err();
        return 0;
    }
    if(c[4]!=0) {
        if(c[4]>c[2] || c[4]>c[1]) {
            err();
            return 0;
        }
        while(c[4]--) {
            s+="1 2 4\n";
            c[2]--;
            c[1]--;
        }
        c[4]+=1;
    }
    if (c[2]!=0) {
        if(c[2]>c[1] || c[2]>c[6]) {
            err();
            return 0;
        }
        while(c[2]--) {
            s+="1 2 6\n";
            c[1]--;
            c[6]--;
        }
        c[2]+=1;
    }
    if (c[3]!=0) {
        if(c[3]!=c[1] || c[3]!=c[6]) {
            err();
            return 0;
        }
        while(c[3]--) {
            s+="1 3 6\n";
            c[1]--;
            c[6]--;
        }
        c[3]+=1;
    }
    for(int i=1; i<=7; i++) {
        if(c[i]!=0) {
            // printf("%d %d",i,c[i]);
            err();
            return 0;
        }
    }
    cout << s;
    return 0;
}