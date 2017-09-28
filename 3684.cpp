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
#define debug(x) cerr << #x <<": "<<x<<endl
#define debug2(x,y) cerr << #x <<": "<< (x) <<", "<< #y <<": "<< (y) << endl
#define answer(x) cout << (x) <<endl
#define answer_fixed(x, p) cout << fixed << setprecision(p) << (x) << endl
using namespace std;
typedef vector<double> VD;

static const double g = 10.0;
int N, H, R, T;

double calc(int T) {
  if(T < 0) { return H; }
  double t = sqrt(2 * H / g);
  int k = (int)(T / t);
  double d = (k % 2 == 0 ? T - k * t : T - k * t - t);
  return H - g * d * d / 2;
}

int main() {
  int case_n;
  cin >> case_n;
  REP(l, case_n) {
    cin >> N >> H >> R >> T;
    VD height(N);
    REP(i, N) { height[i] = calc(T - i); }
    sort(all(height));
    REP(i, N) {
      cout << fixed << setprecision(2) << height[i] + 2 * R * i / 100.0 << (i == N - 1 ? '\n' : ' ');
    }
  }
  return 0;
}

