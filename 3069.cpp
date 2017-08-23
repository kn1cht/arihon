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
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl
using namespace std;
typedef vector<int> VI;

int main() {
  int r, n;
  while(cin >> r >> n, r != -1 || n != -1) {
    VI X;
    REP(i, n) {
      int x;
      cin >> x;
      X.pb(x);
    }
    sort(all(X));
    int ans = 0;
    for(int itr = 0; itr < n; ++itr) {
      int i = itr;
      while(i + 1 < n && X[i + 1] - X[itr] <= r) { ++i; }
      itr = i;
      while(i + 1 < n && X[i + 1] - X[itr] <= r) { ++i; }
      itr = i;
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
