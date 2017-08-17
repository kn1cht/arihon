#include <algorithm>
#include <iostream>
#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define REP(i,n) FOR(i,0,n)
using namespace std;

int main(){
  int l, m, n, a;
  cin >> m;
  REP(i, m) {
    int min_ans = 0, max_ans = 0;
    cin >> l >> n;
    REP(j, n) {
      cin >> a;
      min_ans = max(min(a, l - a), min_ans);
      max_ans = max(max(a, l - a), max_ans);
    }
    cout << min_ans << " " << max_ans << endl;
  }
  return 0;
}
