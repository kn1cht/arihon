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

bool garden[200][200], flag[200][200];

int dx[8] = { 1, 1, 0,-1,-1,-1, 0, 1};
int dy[8] = { 0, 1, 1, 1, 0,-1,-1,-1};

bool dfs(int x, int y, int m, int n) {
  if(!garden[x][y] || flag[x][y]) { return false; }
  flag[x][y] = true;
  REP(i, 8) {
    int nx = max(min(x + dx[i], n), 0);
    int ny = max(min(y + dy[i], m), 0);
    if(garden[nx][ny] && !flag[nx][ny]) {
      dfs(nx, ny, m, n);
    }
  }
  return true;
}

int main(){
  int m, n;
  cin >> n >> m;
  REP(x, n) {
    string str;
    cin >> str;
    REP(y, m) {
      garden[x][y] = (str[y] == 'W') ? true : false;
      flag[x][y] = false;
    }
  }
  int ans = 0;
  REP(x, n) {
    REP(y, m) {
      if(dfs(x, y, m, n)) { ans++; }
    }
  }
  cout << ans << endl;
  return 0;
}
