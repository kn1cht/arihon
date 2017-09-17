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
typedef vector<int> VI;

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

int main() {
  int N, L, P;
  cin >> N;
  vector<pair<int,int> > fuels(N);
  REP(i, N) { cin >> fuels[i].fst >> fuels[i].snd; }
  cin >> L >> P;
  fuels.pb(mp(0, 0));
  sort(rall(fuels));

  priority_queue<int> Q;
  int ans = 0, F = P;
  REP(i, N + 1) {
    int d = L - fuels[i].fst;
    L = fuels[i].fst;

    while(F < d) {
      if(Q.empty()) {
        cout << -1 << endl;
        return 0;
      }
      F += Q.top();
      Q.pop();
      ans++;
    }
    Q.push(fuels[i].snd);
    F -= d;
  }

  cout << ans << endl;
  return 0;
}
