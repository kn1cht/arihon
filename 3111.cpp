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
  cin >> n >> k;
  VI v(n), w(n);
  REP(i, n) { scanf("%d %d", &v[i], &w[i]); }
  double lb = 0.0, ub = 1e8, ans;
  vector<pair<double, int> > jewel;
  REP(i, 50) {
    jewel.clear();
    ans = (lb + ub) / 2;
    REP(i, n) { jewel.pb(mp(v[i] - w[i] * ans, i + 1)); }
    sort(rall(jewel));
    double sum = 0;
    REP(i, k) { sum += jewel[i].fst; }
    if(sum >= 0) { lb = ans; }
    else { ub = ans; }
  }
  REP(i, k) { cout << jewel[i].snd << (i == k - 1 ? '\nr : ' '); }
  return 0;
}
