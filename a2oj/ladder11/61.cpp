#include<bits/stdc++.h>
using namespace std;

int main() {
    long long unsigned n;
    cin >> n;
    long long int a, max_=INT_MIN, min_=INT_MAX, c_max=0, c_min=0;
    for(int i=0; i<n; i++) {
        cin >> a;
        if(a > max_) {
            max_ = a;
            c_max = 1;
        } else if (a==max_)
            c_max++;
        
        if (a<min_) {
            min_ = a;
            c_min = 1;
        } else if(a==min_)
            c_min++;
    }
    long long int diff = max_-min_;
    long long unsigned ways;

    if(diff == 0)
        ways = (n * (n-1))/2;
    else 
        ways = c_min * c_max;

    cout << diff << " " << ways << endl;
    return 0;
}
