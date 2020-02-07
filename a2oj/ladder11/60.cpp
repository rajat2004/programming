#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;

    string s;
    for(int i=0; i<n; i++) {
        cin >> s;
        for(int j=0; j<m; j++) {
            if(s[j]!='-') {
                if((i+j)%2==0) s[j] = 'W';
                else s[j]='B';
            }
        }
        cout << s << endl;
    }
    // int arr[n][m];
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++)
    //         arr[i][j] = 0;
    // }

    // char c;

    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    //         cin >> c;
    //         if(c=='-') arr[i][j]=-1;
    //         else {
    //             int res = 0;
    //             if(i>0 && arr[i-1][j]!=-1) res = res || arr[i-1][j];
    //             if(j>0 && arr[i][j-1]!=-1) res = res || arr[i][j-1];
    //             // if(i<n-1 && arr[])
    //             if(res==0) arr[i][j]=1;
    //             else arr[i][j]=0;
    //         }
    //     }
    // }

    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    //         switch(arr[i][j]) {
    //             case -1:
    //                 cout << "-";
    //                 break;

    //             case 0:
    //                 cout << "W";
    //                 break;

    //             case 1:
    //                 cout << "B";
    //                 break;
    //         }
    //     }
    //     cout << endl;
    // }
    return 0;
}
