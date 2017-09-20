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
//#include <bits/stdc++.h>
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
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef pair<int, int> PII;

int main() {
  return 0;
}

// initialization
template<typename A, size_t N, typename T> void FILL(A (&array)[N], const T &val){
  fill( (T*)array, (T*)(array+N), val );
}

// pair
template<typename T1, typename T2> ostream& operator<<(ostream& s, const pair<T1, T2>& p) {
  return s << "(" << p.first << ", " << p.second << ")";
}
// vector
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i]; if (i < len - 1) s << "\t";
  }
  return s;
}
// 2 dimentional vector
template<typename T> ostream& operator<<(ostream& s, const vector< vector<T> >& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) {
    s << vv[i] << endl;
  }
  return s;
}

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
  vector<vector<PII> > data; // fst : to, snd : cost
  vector<edge> data_e;
  Graph(int size) : N(size + 1), data(N) {}

  VI dijkstra(int s) {
    priority_queue<PII, vector<PII>, greater<PII> > PQ;
    VI distance(N, 1e9);
    distance[s] = 0;
    PQ.push(mp(0, s));
    while(!PQ.empty()) {
      PII p = PQ.top(); PQ.pop();
      int v = p.snd;
      if(distance[v] < p.fst) { continue; }
      for(const auto & e : data[v]) {
        if(distance[e.fst] > distance[v] + e.snd) {
          distance[e.fst] = distance[v] + e.snd;
          PQ.push(mp(distance[e.fst], e.fst));
        }
      }
    }
    return distance;
  }
  /* ***use data_e for kruskal method***

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
  */
};

// complex
typedef complex<double> xy_t;
double dot_product(xy_t a, xy_t b){ return (conj(a) * b).real(); }
double cross_product(xy_t a, xy_t b){ return (conj(a) * b).imag(); }
xy_t projection(xy_t p, xy_t b) {return b * dot_product(p,b) / norm(b);}

// GCD
int gcd(int a, int b) {
  if(b == 0) { return a; }
  return gcd(b, a % b);
}

// Prime
bool is_prime(int n) {
  for(int i = 2; i * i <= n; ++i) {
    if(n % i == 0) { return false; }
  }
  return n != 1;
}
VI divisor(int n) {
  VI res;
  for(int i = 1; i * i <= n; ++i) {
    if(n % i == 0) {
      res.pb(i);
      if(i != n / i) { res.pb(n / i); }
    }
  }
  return res;
}
map<int, int> prime_factor(int n) {
  map<int, int> res;
  for(int i = 2; i * i <= n; ++i) {
    while(n % i == 0) {
      ++res[i];
      n /= i;
    }
  }
  if(n != 1) { res[n] = 1; }
  return res;
}
int sieve(int n) {
  VI prime;
  VB is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for(int i = 2; i <= n; ++i) {
    if(is_prime[i]) {
      prime.pb(i);
      for(int j = 2 * i; j <= n; j += i) { is_prime[j] = false; }
    }
  }
  return prime.size();
}

// Power
long long mod_pow(long long x, long long n, long long mod) {
  if(n == 0) { return 1; }
  long long res = mod_pow(x * x % mod, n >> 1, mod);
  if(n & 1) { res = res * x % mod; }
  return res;
}
