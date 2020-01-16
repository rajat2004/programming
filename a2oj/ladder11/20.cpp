#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    int a;
    scanf("%d", &a);
    v.push_back(a);
    while(scanf("+%d", &a))
        v.push_back(a);
    sort(v.begin(), v.end());
    cout << v[0];
    for(int i=1; i<v.size(); i++) {
        cout << "+" << v[i];
    }
    return 0;
}