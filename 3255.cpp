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
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;

// Dijkstra
struct Graph {
  const int N;
  vector<vector<PII> > data; // fst : to, snd : cost
  Graph(int size) : N(size + 1), data(N) {}

  VI dijkstra(int s) {
    priority_queue<PII, vector<PII>, greater<PII> > PQ;
    VI distance(N, 1e9);
    distance[s] = 0;
    VI distance_2(N, 1e9);
    PQ.push(mp(0, s));
    while(!PQ.empty()) {
      PII p = PQ.top(); PQ.pop();
      int v = p.snd;
      if(distance_2[v] < p.fst) { continue; }
      REP(i, data[v].size()) {
        PII e = data[v][i];
        int d2 = p.fst + e.snd;
        if(distance[e.fst] > d2) {
          swap(distance[e.fst], d2);
          PQ.push(mp(distance[e.fst], e.fst));
        }
        if(distance_2[e.fst] > d2 && distance[e.fst] < d2) {
          distance_2[e.fst] = d2;
          PQ.push(mp(distance_2[e.fst], e.fst));
        }
      }
    }
    return distance_2;
  }
};


int main() {
  int N, R, u, v, c;
  cin >> N >> R;
  Graph G(N);
  REP(i, R) {
    cin >> u >> v >> c;
    G.data[u].pb(mp(v, c));
    G.data[v].pb(mp(u, c));
  }
  cout << G.dijkstra(1)[N] << endl;
  return 0;
}

