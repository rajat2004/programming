#include<bits/stdc++.h>
using namespace std;

bool compare_pairs(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first != p2.first)
        return p1.first < p2.first;
    else 
        return p1.second < p2.second;
}

int main(){
    int s, n;
    cin >> s >> n;
    pair<int, int> arr[n];
    for(int i=0; i<n; i++) 
        cin >> arr[i].first >> arr[i].second;
    
    sort(arr, arr+n, compare_pairs);
    // for(int i=0; i<n; i++)
    //     cout << arr[i].first << " " << arr[i].second << endl;

    int curr_strength = s;
    for(int i=0; i<n; i++) {
        if(arr[i].first >= curr_strength) {
            cout << "NO" << endl;
            return 0;
        }
        else {
            curr_strength += arr[i].second;
        }
    }
    cout << "YES" << endl;
    return 0;
}