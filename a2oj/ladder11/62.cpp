#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2) {
    return p1.first<p2.first;
}

int main() {
    int n, a;
    cin >> n;
    vector<int> v[100002];

    for(int i=0; i<n; i++) {
        cin >> a;
        v[a].push_back(i);
    }

    vector<pair<int, int>> res;
    for(int i=1; i<100001; i++) {
        if(v[i].size() == 0)
            continue;
        if(v[i].size() == 1)
            res.push_back(make_pair(i, 0));
        else {
            sort(v[i].begin(), v[i].end());
            int d = v[i][1] - v[i][0];
            int flag = 1;
            for(int j=2; j<v[i].size(); j++) {
                if (v[i][j] - v[i][j-1] != d) {
                    flag = 0;
                    break;
                }
            }
            if(flag==1)
                res.push_back(make_pair(i, d));
        }
    }

    sort(res.begin(), res.end(), comp);

    cout << res.size() << endl;
    for(int i=0; i<res.size(); i++) {
        cout << res[i].first << " " << res[i].second << endl;
    }
    return 0;
}
