#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define RFOR(i,k,n) for (int (i)=(n)-1; (i)>=(k); --(i))
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl
using namespace std;
//static const int INF = 1e9;
//static const double PI = acos(-1.0);
//static const double EPS = 1e-10;
//static const int dx[8] = { 1, 1, 0,-1,-1,-1, 0, 1};
//static const int dy[8] = { 0, 1, 1, 1, 0,-1,-1,-1};
typedef long long int LL;
typedef unsigned long long int ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;


// Union-Find Tree
struct Union {
  VI data;
  Union(int size) : data(size, -1) {}
  bool unite(int x, int y) {
    if (x = root(x), y = root(y), x != y) {
      if (data[y] < data[x]) { swap(x, y); }
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool find(int x, int y) { return root(x) == root(y); }
  int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
  int size(int x) { return -data[root(x)]; }
};

// Graph algorithm
struct edge { int u, v, c; };
bool comp_e(const edge& e1, const edge& e2) { return e1.c < e2.c; }
struct Graph {
  const int N;
  vector<edge> data_e;
  Graph(int size) : N(size + 1), data_e(N) {}

  int kruskal(int V) {
    sort(all(data_e), comp_e);
    Union U(V);
    int res = 0;
    REP(i, N) {
      edge e = data_e[i];
      if(!U.find(e.u, e.v)) {
        U.unite(e.u, e.v);
        res += e.c;
      }
    }
    return res;
  }
};

int main() {
  int T, N, M, R, x, y, d;
  cin >> T;
  REP(i, T) {
    cin >> N >> M >> R;
    Graph G(R);
    REP(i, R) {
      scanf("%d %d %d", &x, &y, &d);
      G.data_e[i] = (edge){x, y + N, -d};
    }
    cout << 10000 * (N + M) + G.kruskal(N + M) << endl;
  }
  return 0;
}

