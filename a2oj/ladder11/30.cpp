#include<bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, int> mp;
    int n,a;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a;
        mp[a] = i+1;
    }
    int m,num;
    cin >> m;
    long long int left_count=0, right_count = 0;
    for(int i=0; i<m; i++) {
        cin >> num;
        int index = mp.find(num)->second;
        left_count+=index;
        right_count += n+1 - index;
    }
    cout << left_count << " " << right_count << endl;
    return 0;
}