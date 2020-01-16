#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, l, r;
    cin >> n;
    int left_open_count=0, right_open_count=0;
    for(int i=0; i<n; i++) {
        cin >> l >> r;
        if(l==0)
            left_open_count+=1;
        if(r==0)
            right_open_count+=1;
    }
    int time = 0;
    if(left_open_count < (n-left_open_count)) 
        time += left_open_count;
    else 
        time += (n-left_open_count);

    if(right_open_count < (n-right_open_count))
        time += right_open_count;
    else 
        time += (n-right_open_count);
    
    cout << time << endl;
    return 0;
}