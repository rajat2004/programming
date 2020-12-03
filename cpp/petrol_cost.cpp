#include <bits/stdc++.h>
using namespace std;
using v32 = vector<int>;
using p32 = pair<int,int>;
using graph = vector<vector<p32>>;

using ll = long long;

ll min_cost = 1e15;
int cap;

int getDist(const graph &g, int u, int v) {
    for(const auto &p:g[u]) {
        if (p.first == v)
            return p.second;
    }
}

void calcMinCost(const vector<int> &path, const graph &g, const v32 &frpice) {
    ll cost=0;
    int n=path.size(), curr_use=0;
    for(int i=n-1; i>=0; i--) {
        // if (curr_use < cap) {

        // }
        int req = getDist(g, path[i], path[i+1]);

    }
}

void genPaths(int id, int dest, const graph &g, vector<bool> &visited, vector<int> &path, const v32 &fprice) {
    visited[id] = true;
    path.push_back(id);

    if (id==dest) {
        // Just print for now
        // for(auto v:path)
        //     cout << v << " ";
        // cout << endl;
        calcMinCost(path, g, fprice);
    }
    else {
        for(auto v:g[id]) {
            if (!visited[v.first])
                genPaths(v.first, dest, g, visited, path, fprice);
        }
    }

    visited[id] = false;
    path.pop_back();
}

int minimumAmount(int N,int M,int S,int C, vector<v32> &road, vector<v32> &fuel,int A,int B)
// N is the number of cities, M is the number of roads between these cities and S is the number of fuel stations
// C is capacity of the car's fuel tank in litres
// Each row of the array 'road' has 3 integers X,Y and G indicating that there is a bidirectional road between cities X and Y and G litres of fuel is needed to travel between X and Y.
// Each row of the array 'fuel' has 2 integers Q and P, where Q is the city that has fuel station and P is the price per litre of fuel at that station.
//  A is the starting city and B is the final destination.
{
    int res=0;

    // WRITE YOUR CODE HERE

    cap = C;

    graph g(N);
    for(auto &e:road) {
        g[e[0]-1].push_back({e[1]-1, e[2]});
        g[e[1]-1].push_back({e[0]-1, e[2]});
    }

    v32 fprice(N, INT_MAX);
    for(auto &f:fuel)
        fprice[f[0]-1] = f[1];

    vector<bool> visited(N, false);
    vector<int> path;

    genPaths(A-1, B-1, g, visited, path, fprice);

    return res;
}

int main()
{
    int N,M,S,C,A,B;
    cin>>N>>M>>S;
    cin>>C;
    vector<v32> road(M, v32(3, 0));
    vector<v32> fuel(S, v32(2,0));
    for(int i=0; i<M; i++)
        cin>>road[i][0]>>road[i][1]>>road[i][2];
    for(int j=0; j<S; j++)
        cin>>fuel[j][0]>>fuel[j][1];
    cin>>A>>B;
    cout<<minimumAmount(N,M,S,C,road,fuel,A,B);
    return 0;
}

/*
Example input 1

3 3 2
2000
1 3 800
1 2 500
2 3 500
1 70
2 40
1 3

Output - 55000

Example Input 2

5 5 3
1000
1 2 800
2 5 800
1 3 400
3 4 600
4 5 600
1 80
2 90
3 20
1 5

Output - 134000

*/
