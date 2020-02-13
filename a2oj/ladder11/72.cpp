#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,l,r,max_r=INT_MIN,min_l=INT_MAX;
    cin >> n;
    vector<pair<int,int>> v;
    for(int i=1; i<=n; i++) {
        cin >> l >> r;
        if (l<=min_l)
            min_l=l;
        if(r>max_r)
            max_r = r;
        v.push_back(make_pair(l,r));
    }
    for(int i=0; i<n; i++) {
        if(v[i].first==min_l && v[i].second==max_r) {
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
