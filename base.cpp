#include <bits/stdc++.h>
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

int main() {
  return 0;
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

// Dijkstra
struct Graph {
  const int N;
  vector<vector<PII> > data; // fst : to, snd : cost
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
};

// complex
typedef complex<double> xy_t;
double dot_product(xy_t a, xy_t b){ return (conj(a) * b).real(); }
double cross_product(xy_t a, xy_t b){ return (conj(a) * b).imag(); }
xy_t projection(xy_t p, xy_t b) {return b * dot_product(p,b) / norm(b);}

