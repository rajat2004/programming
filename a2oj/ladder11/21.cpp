#include<bits/stdc++.h>
using namespace std;

int main() {
    unordered_set<int> m;
    int count = 0,a;
    for(int i=0; i<4; i++) {
        cin >> a;
        if(m.find(a) == m.end())
            m.insert(a);
        else 
            count += 1;
    }
    cout << count << endl;
    return 0;
}