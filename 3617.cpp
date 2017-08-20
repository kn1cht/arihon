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
#define REP(i,n) FOR(i,0,n)
using namespace std;

char s[2000], t[2000];

int main() {
  int n;
  cin >> n;
  REP(i, n) { cin >> s[i]; }
  int a = 0, b = n - 1, i = 0;
  while(a <= b) {
    bool is_left = 1;
    REP(j, b - a) {
      if(s[a + j] == s[b - j]) { continue; }
      is_left = s[a + j] < s[b - j];
      break;
    }
    t[i++] = is_left ? s[a++] : s[b--];
  }
  REP(i, n) {
    cout << t[i];
    if((i + 1) % 80 == 0) { cout << endl; }
  }
  return 0;
}
