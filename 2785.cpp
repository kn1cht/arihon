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

typedef vector<int> VI;

const int MAX_N = 4000;
int AB[MAX_N * MAX_N];
int CD[MAX_N * MAX_N];

int main() {
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  VI A(N), B(N), C(N), D(N);
  REP(i, N) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
  }
  REP(i, N) {
    REP(j, N) {
      AB[i + N * j] = A[i] + B[j];
      CD[i + N * j] = C[i] + D[j];
    }
  }
  sort(AB, AB + N * N);
  long long ans = 0;
  REP(i, N * N) { // each val in CD 
    ans += upper_bound(AB, AB + N * N, -CD[i]) - lower_bound(AB, AB + N * N, -CD[i]);
  }
  answer(ans);
  return 0;
}

