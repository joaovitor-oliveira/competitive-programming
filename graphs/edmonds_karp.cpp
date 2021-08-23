#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

const ll modn = (ll)1e9+7;
inline ll mod(ll x) { return x % modn; }
const int inf = (1 << 30);
const ll linf = (1LL << 60);

#define inf (1 << 30)

const int MAXN = 40;
const int MAXM = 400;

int ned, prv[MAXN], first[MAXM];
int cap[MAXM], to[MAXM], nxt[MAXM], dist[MAXN];

void add(int u, int v, int f);

void init(int n) {
  memset(&first, -1, sizeof first);
  ned = 0;
  for(int i = 1; i <= 6; ++i)
    add(0, i, n);
}

void add(int u, int v, int f) {
  to[ned] = v, cap[ned] = f;
  nxt[ned] = first[u];
  first[u] = ned++;
  to[ned] = u, cap[ned] = 0;
  nxt[ned] = first[v];
  first[v] = ned++;
}

int augment(int v, int minEdge, int s) {
  int e = prv[v];
  
  if(e == -1) return minEdge;
  
  int f = augment(to[e ^ 1], min(minEdge, cap[e]), s);
  cap[e] -= f;
  cap[e ^ 1] += f;

  return f;
}

bool bfs(int s, int t) {
  int u, v;
  memset(&dist, -1, sizeof dist);

  dist[s] = 0;
  queue<int> q;
  q.push(s);

  memset(&prv, -1, sizeof prv);
  while(!q.empty()) {
    u = q.front(); q.pop();

    if(u == t) break;

    for(int e = first[u]; e != -1; e = nxt[e]) {
      v = to[e];
      if(dist[v] < 0 && cap[e] > 0) {
        dist[v] = dist[u] + 1;
        q.push(v);
        prv[v] = e;
      }
    }
  }

  return dist[t] >= 0;
}

int edmondsKarp(int s, int t) {
  int res = 0;
  while(bfs(s, t))
    res += augment(t, inf, s);

  return res;
}

int main() {
  
  return 0;
}
