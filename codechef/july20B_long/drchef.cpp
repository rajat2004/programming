#pragma GCC optimize ("-O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long long unsigned lluu;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
ll NUM = 1e9+7;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define INF 1e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define zer ll(0)

int find_country(int* arr, int n, int x) {
    int max_less=INT_MIN, max_less_idx;
    int max_el = INT_MIN, idx=-1;

    forn(i,n) {
        if (arr[i]<=x) {
            if(arr[i]>max_less) {
                max_less = arr[i];
                max_less_idx = i;
            }
        }

        if(max_el < arr[i]) {
            max_el = arr[i];
            idx = i;
        }
    }

    // x is greater than everything
    if (max_less == max_el)
        return INT_MAX;

    if (max_less <= (x/2))
        // Use max element overall
        return idx;
    else
        return max_less_idx;
}

int non_zeros(int* arr, int n) {
    int c = 0;
    forn(i,n) {
        c += (arr[i]!=0);
    }
    return c;
}

void print_arr(int* arr, int n) {
    forn(i,n) cout << arr[i] << " ";
    cout << ln;
}

int main() {
    fast_cin();
    int t;
    cin >> t;
    while(t--) {
        ll n,x;
        cin >> n >> x;
        int arr[n];
        forn(i,n)   cin >> arr[i];

        int orig[n];
        forn(i,n)   orig[i] = arr[i];

        int total = 0;

        while(true) {
            int idx = find_country(arr, n, x);
            // print_arr(arr, n);
            // dbg(idx);
            // dbg(x);
            // dbg(total);

            if(idx==INT_MAX) {
                // x is greater than everything, count non-zeros and done
                total += non_zeros(arr, n);
                break;
            }

            total+=1;
            if(arr[idx]<=x) {
                x = arr[idx];
                arr[idx]=0;
            }
            else
                arr[idx] -= x;

            // Update array
            forn(i,n) {
                if(arr[i]!=orig[i]) {
                    arr[i] = min(2*arr[i], orig[i]);
                }
            }
            x*=2;
        }


        cout << total << ln;
    }
    return 0;
}
