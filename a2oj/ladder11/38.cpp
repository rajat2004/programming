#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long int min_time=INT_MAX,a, count = 0, index;
    for(int i=0; i<n; i++) {
        cin >> a;
        if (a < min_time) {
            min_time = a;
            count = 0;
            index = i;
        } else if (a==min_time)
            count+=1;
    }
    if (count==0)
        cout << index+1 << endl;
    else 
        cout << "Still Rozdil" << endl;
    return 0;
}