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
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<char> VC;
typedef vector<VC> VVC;

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

//幾何問題用・複素数
typedef complex<double> xy_t;
double dot_product(xy_t a, xy_t b){ return (conj(a) * b).real(); }
double cross_product(xy_t a, xy_t b){ return (conj(a) * b).imag(); }
xy_t projection(xy_t p, xy_t b) {return b * dot_product(p,b) / norm(b);}

int main() {
  int n, m, M;
  cin >> n >> m >> M;
  VVI dp(m + 1, VI(n + 1, 0));
  dp[0][0] = 1;
  FOR(i, 1, m + 1) {
    REP(j, n + 1) {
      dp[i][j] = ((j >= i) ? (dp[i - 1][j] + dp[i][j - i]) % M : dp[i - 1][j]);
      debug2(i, j);
      debug(dp);
    }
  }
  cout << dp[m][n];
  return 0;
}
