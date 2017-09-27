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

int main() {
  int P;
  cin >> P;
  VI A(P);
  set<int> S;
  REP(i, P) {
    scanf("%d", &A[i]);
    S.insert(A[i]);
  }
  int n = S.size();
  int st = 0, en = 0, ans = P + 1, num = 0;
  map<int, int> count;
  for(;;) {
    while(en < P && num < n) {
      if(count[A[en++]]++ == 0)  { num++; }
    }
    if(num < n) { break; }
    ans = min(ans, en - st);
    if(--count[A[st++]] == 0) { num--; }
  }
  cout << ans << endl;
  return 0;
}

