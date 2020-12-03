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
#define printarr(arr,n) forn(i,n)   cout << arr[i] << " "
#define input(arr,n) forn(i,n)  cin >> arr[i]
#define yes() cout << "Yes" << ln
#define no() cout << "No" << ln

const string FAIL = "failure";
const string SUCC = "success";

class Screen {
private:
    int nrows, seats_per_row;
    unordered_set<int> aisle_seats;

    vector<vector<bool>> seats_occ;

    bool isaisle(int i) {
        return aisle_seats.find(i)!=aisle_seats.end();
    }

public:
    // Screen(int nrows, int seats_per_row, vector<int> aseats)
    // : nrows(nrows), seats_per_row(seats_per_row)
    // {
    //     for(auto s:aseats)
    //         aisle_seats.insert(s);

    //     seats_occ = vector<vector<bool>>(nrows, vector<bool>(seats_per_row, false));
    // }

    bool create(int nrows_, int seats_per_row_, vector<int> aseats)
    {
        nrows = nrows_;
        seats_per_row = seats_per_row_;

        for(auto s:aseats)
            aisle_seats.insert(s);

        seats_occ = vector<vector<bool>>(nrows, vector<bool>(seats_per_row, false));
    }

    bool reserve(int rowno, const vector<int> &seats)
    {
        for(auto s:seats) {
            if (seats_occ[rowno-1][s-1])
                return false;
        }

        for(auto s:seats)
            seats_occ[rowno-1][s-1] = true;

        return true;
    }

    vector<int> getUnreservedSeats(int rowno)
    {
        vector<int> unres_seats;
        for(int i=0; i<seats_per_row; i++) {
            if (!seats_occ[rowno-1][i])
                unres_seats.push_back(i+1);
        }

        return unres_seats;
    }

    bool suggestLeft(int tot_seats, int rowno, int choice, vector<int> &suggestions)
    {
        int left_lim = choice-tot_seats;
        if (left_lim < 0)
            return false;

        bool is_aisle = isaisle(choice);
        suggestions.push_back(choice);

        for(int i=choice-1; i>(left_lim+1); i--) {
            if (seats_occ[rowno-1][i-1])
                return false;

            if (isaisle(i))
                return false;

            suggestions.push_back(i);
        }

        if (seats_occ[rowno-1][left_lim])
            return false;

        if (isaisle(left_lim+1) && is_aisle)
            return false;

        suggestions.push_back(left_lim+1);

        return true;
    }

    bool suggestRight(int tot_seats, int rowno, int choice, vector<int> &suggestions)
    {
        int right_lim = choice + tot_seats;
        if (right_lim >= seats_per_row+1)
            return false;

        bool is_aisle = isaisle(choice);
        suggestions.push_back(choice);

        for(int i=choice+1; i<(right_lim-1); i++) {
            if (seats_occ[rowno-1][i-1])
                return false;

            if (isaisle(i))
                return false;

            suggestions.push_back(i);
        }

        if (seats_occ[rowno-1][right_lim-2])
            return false;

        if (isaisle(right_lim-1) && is_aisle)
            return false;

        suggestions.push_back(right_lim-1);

        return true;
    }

    vector<int> suggestSeats(int tot_seats, int rowno, int choice)
    {
        if (seats_occ[rowno-1][choice-1])
            return {};

        vector<int> suggested;
        auto ret = suggestLeft(tot_seats, rowno, choice, suggested);

        if (ret)
            return suggested;
        else
            suggested.clear();

        ret = suggestRight(tot_seats, rowno, choice, suggested);
        if (ret)
            return suggested;
        else
            suggested.clear();

        return suggested;

        // if (choice-tot_seats >= 0) {
        //     vector<int> suggest{choice};

        //     bool left_possible = true;

        //     for(int i=choice-1; i>=1; i--) {
        //         if (seats_occ[rowno-1][i-1] || isaisle(i)) {
        //             left_possible = false;
        //             break;
        //         }
        //         else
        //             suggest.push_back(i);
        //     }

        //     if (left_possible)
        //         reverse(suggest.begin(), suggest.end());
        //     else
        //         suggest.clear();

        //     return suggest;
        // }

        // if (choice+tot_seats <= seats_per_row+1) {
        //     vector<int> suggest{choice};

        //     bool right_possible = true;

        //     for(int i=choice+1; i<seats_per_row; i++) {
        //         if (seats_occ[rowno-1][i-1] || isaisle(i)) {
        //             right_possible = false;
        //             break;
        //         }
        //         else
        //             suggest.push_back(i);
        //     }

        //     if (!right_possible)
        //         suggest.clear();

        //     return suggest;
        // }

        // return {};
    }
};

int main() {
    // fast_cin();

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    unordered_map<string, Screen> all_screens;

    while(n > 0) {
        string s;
        getline(cin, s);

        cout << s << endl;

        stringstream ss(s);
        string op;

        ss >> op;

        cout << op << endl;
        cout << n << endl;

        if (op=="add-screen") {
            string name;
            ss >> name;

            if (all_screens.find(name)!=all_screens.end()) {
                cout << FAIL << endl;
                continue;
            }

            int nrows, seats_per_row;
            vector<int> aisle_seats;

            ss >> nrows >> seats_per_row;
            int x;
            while(ss >> x)
                aisle_seats.push_back(x);

            // all_screens[name] = Screen(nrows, seats_per_row, aisle_seats);
            // all_screens.insert({name, Screen(nrows, seats_per_row, aisle_seats)});
            all_screens.insert({name, Screen()});
            all_screens[name].create(nrows, seats_per_row, aisle_seats);

            cout << SUCC << endl;
        }

        else if (op=="reserve-seat") {
            string name;
            ss >> name;

            if (all_screens.find(name)==all_screens.end()) {
                cout << FAIL << endl;
                continue;
            }

            int rowno;
            vector<int> seats;

            ss >> rowno;
            int x;
            while(ss >> x)
                seats.push_back(x);

            auto res = all_screens[name].reserve(rowno, seats);

            if (res)
                cout << SUCC << endl;
            else
                cout << FAIL << endl;
        }

        else if (op=="get-unreserved-seats") {
            string name;
            ss >> name;

            if (all_screens.find(name)==all_screens.end()) {
                cout << FAIL << endl;
                continue;
            }

            int rowno;
            ss >> rowno;

            auto res = all_screens[name].getUnreservedSeats(rowno);
            printarr(res, res.size());
            cout << endl;
        }

        else if (op=="suggest-contiguous-seats") {
            cout << "Suggest" << endl;
            string name;
            ss >> name;

            if (all_screens.find(name)==all_screens.end()) {
                cout << FAIL << endl;
                continue;
            }

            int tot_seats, rowno, seat_no;
            ss >> tot_seats >> rowno >> seat_no;

            auto res = all_screens[name].suggestSeats(tot_seats, rowno, seat_no);
            if (res.size()) {
                printarr(res, res.size());
                cout << endl;
            }
                // cout << SUCC << endl;
            else
                cout << "none" << endl;
                // cout << FAIL << endl;
        }

        n--;
    }

    return 0;
}
