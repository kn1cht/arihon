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
typedef vector<double> VD;
typedef vector<VD> VVD;


int main() {
  int N, K;
  cin >> N >> K;
  double sum = 0.0;
  VD L(N);
  REP(i, N) {
    scanf("%lf", &L[i]);
    sum += L[i];
  }
  double max_ans = sum / K;
  double min_ans = 0.0;
  double mid;
  REP(i, 100) {
    mid = (max_ans + min_ans) / 2;
    int cable_num = 0;
    REP(j, N) {
      cable_num += floor(L[j] / mid);
      if(cable_num >= K) { break; }
    }
    if(cable_num >= K) { min_ans = mid; }
    else { max_ans = mid; }
  }
  cout << fixed << setprecision(2) << floor(max_ans * 100) / 100.0 << endl;
  return 0;
}
