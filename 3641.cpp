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
//static const int INF = 1e9;
//static const double PI = acos(-1.0);
//static const double EPS = 1e-10;
//static const int dx[8] = { 1, 1, 0,-1,-1,-1, 0, 1};
//static const int dy[8] = { 0, 1, 1, 1, 0,-1,-1,-1};
typedef long long int LL;
typedef unsigned long long int ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef pair<int, int> PII;

// Prime
bool is_prime(int n) {
  for(int i = 2; i * i <= n; ++i) {
    if(n % i == 0) { return false; }
  }
  return n != 1;
}

long long mod_pow(long long x, long long n, long long mod) {
  if(n == 0) { return 1; }
  long long res = mod_pow(x * x % mod, n >> 1, mod);
  if(n & 1) { res = res * x % mod; }
  return res;
}

int main() {
  int p, a;
  while(cin >> p >> a, p && a) {
    if(is_prime(p)) {
      cout << "no" << endl;
      continue;
    }
    cout << ((mod_pow(a, p, p) % p == a) ? "yes" : "no") << endl;
  }
  return 0;
}
