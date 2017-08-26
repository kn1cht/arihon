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

int main() {
  int n, len = 0;
  VI L;
  cin >> n;
  REP(i,n) {
    int tmp;
    cin >> tmp;
    L.pb(tmp);
    len += tmp;
  }
  sort(all(L));
  LL ans = 0;
  while(L.length()) {
    int t = L[0] + L[1];

    ans += t;
  }
  cout << ans << endl;
  return 0;
}
