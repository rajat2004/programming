#include<bits/stdc++.h>
using namespace std;

int main(){
    int count[3][3];
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++)
            cin >> count[i][j];
    }
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            int sum = 0;
            for(int m=i-1; m<=i+1; m++) {
                if(m>=0 && m<3)
                    sum+=count[m][j];
            }
            for(int n=j-1; n<=j+1; n++) {
                if (n>=0 && n<3)
                    sum += count[i][n];
            }
            sum-=count[i][j];
            if (sum%2==0)
                cout << "1";
            else
                cout << "0";
        }
        cout << endl;
    }
    return 0;
}