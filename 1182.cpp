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
#define rall(v) v.rbegin(), v.rend()
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl
using namespace std;

// Union-Find Tree
struct Union {
  vector<int> data;
  Union(int size) : data(size, -1) {}
  bool unite(int x, int y) {
    if (x = root(x), y = root(y), x != y) {
      if (data[y] < data[x]) { swap(x, y); }
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool find(int x, int y) { return root(x) == root(y); }
  int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
  int size(int x) { return -data[root(x)]; }
};

int N, K;
Union U(150000);

bool isnt_type1(int x, int y) {
  return U.find(x, y + N) || U.find(x, y + 2 * N);
}

bool isnt_type2(int x, int y) {
  return U.find(x, y) || U.find(x, y + 2 * N);
}

int main() {
  int ans = 0;
  cin >> N >> K;
  REP(i, K) {
    int t, x, y;
    scanf("%d %d %d",&t,&x,&y);
    if(x < 1 || y < 1 || x > N || y > N) { ans++; }
    else if(t == 1) {
      if (isnt_type1(x, y)) { ans++; }
      else {
        U.unite(x, y);
        U.unite(x + N, y + N);
        U.unite(x + 2 * N, y + 2 * N);
      }
    }
    else { // type 2
      if (isnt_type2(x, y)) { ans++; }
      else {
        U.unite(x, y + N);
        U.unite(x + N, y + 2 * N);
        U.unite(x + 2 * N, y);
      }
    }
  }

  cout << ans << endl;
  return 0;
}
