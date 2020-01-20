#include<bits/stdc++.h>
using namespace std;

int matrix[2001][2001];

bool check_supercentral(int x, int y) {
    bool left=false, right=false, upper=false, lower=false;
    // Check left
    for(int i=x-1; i>=0; i--) {
        if(matrix[i][y]) {
            left = true;
            break;
        }
    }

    // Check right
    for(int i=x+1; i<2001; i++) {
        if(matrix[i][y]) {
            right = true;
            break;
        }
    }

    // Check lower
    for(int i=y+1; i<2001; i++) {
        if(matrix[x][i]) {
            lower = true;
            break;
        }
    }

    // Check upper
    for(int i=y-1; i>=0; i--) {
        if(matrix[x][i]) {
            upper = true;
            break;
        }
    }

    return (left && right && upper && lower);
}

int main() {
    memset(matrix, 0, sizeof(matrix));
    int n,x,y;
    vector<pair<int,int>> v;
    cin >> n;
    for(int i=0 ;i<n; i++) {
        cin >> x >> y;
        matrix[x+1000][y+1000] = 1;
        v.push_back(make_pair(x+1000, y+1000));
    }

    int count = 0;
    for(int i=0; i<n; i++) {
        if(check_supercentral(v[i].first, v[i].second))
            count+=1;
    }
    cout << count << endl;
    return 0;
}