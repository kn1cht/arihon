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
typedef vector<int> VI;
typedef vector<double> VD;

int main() {
  int n, k;
  while(cin >> n >> k, n || k) {
    VI a(n), b(n);
    REP(i, n) { scanf("%d", &a[i]); }
    REP(i, n) { scanf("%d", &b[i]); }
    double lb = 0.0, ub = 100.0, ans;
    while(ub - lb > 1e-3) {
      ans = (lb + ub) / 2;
      VD score;
      REP(i, n) { score.pb(100.0 * a[i] - b[i] * ans); }
      sort(all(score));
      double score_sum = 0;
      FOR(i, k, n) { score_sum += score[i]; }
      if(score_sum >= 0) { lb = ans; }
      else { ub = ans; }
    }
    cout << fixed << setprecision(0) << ans << endl;
  }
  return 0;
}
