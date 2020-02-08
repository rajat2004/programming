#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, s1,s2,e1,e2;
    cin >> t >> s1 >> s2 >> e1 >> e2;
    int x = e1-s1, y=e2-s2;
    char c;
    int secs = -1;
    while(t >= 0) {
        scanf("%c", &c);
        if(c=='N' && y>0)   y--;
        if(c=='S' && y<0)   y++;
        if(c=='E' && x>0)   x--;
        if(c=='W' && x<0)   x++;

        secs++;
        t--;
        // cout << t << endl;
        // cout << c << endl;
        // cout << x << ' ' << y << endl;
        if(x==0 && y==0) {
            // cout << c << endl;
            cout << secs << endl;
            return 0;
        }
    }
    // cout << x << " " << y << endl;
    cout << "-1" << endl;
    return 0;
}
