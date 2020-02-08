#include<bits/stdc++.h>
using namespace std;

int main() {
    int mat[5][5];
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++)
            cin >> mat[i][j];
    }
    int arr[5] = {0,1,2,3,4};
    int max = INT_MIN;
    int count = 0;
    do 
    {
        count++;
        int sum = mat[arr[0]][arr[1]] + mat[arr[1]][arr[0]] +
                  2*(mat[arr[2]][arr[3]] + mat[arr[3]][arr[2]]) +
                  mat[arr[1]][arr[2]] + mat[arr[2]][arr[1]] +
                  2*(mat[arr[3]][arr[4]] + mat[arr[4]][arr[3]]);
                  
        if(sum > max)
            max = sum;
    } while (next_permutation(arr, arr+5));
    cout << max << endl;
    // cout << count << endl;
    return 0;
}
