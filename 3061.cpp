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
static const int INF = 1e9;
typedef vector<int> VI;

int main() {
  ios_base::sync_with_stdio(false);
  int case_num, N, S;
  cin >> case_num;
  REP(h, case_num) {
    cin >> N >> S;
    VI V(N);
    REP(i, N) { cin >> V[i]; }
    int st = 0, en = 0, ans = INF, sum = 0;
    for(;;) {
      while(en < N && sum < S) { sum += V[en++]; }
      if(sum < S) { break; }
      ans = min(ans, en - st);
      sum -= V[st++];
    }
    if(ans > N) { ans = 0; }
    answer(ans);
  }
  return 0;
}
