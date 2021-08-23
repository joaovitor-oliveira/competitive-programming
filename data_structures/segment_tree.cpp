#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll modn = (ll)1e9 + 7;
inline ll mod(ll x) { return x % modn; }

const int MAXN = (int)1e5 + 5;

inline int left(int p) { return p << 1; }
inline int right(int p) { return (p << 1) + 1; }

int n;
ll arr[MAXN], st[4 * MAXN];

void build(int p, int l, int r) {
  if(l == r)
    st[p] = arr[l];
  else {
    int m = (l + r) / 2;
    build(left(p), l, m);
    build(right(p), m + 1, r);
    
    st[p] = st[left(p)] + st[right(p)];
  }
}

ll query(int p, int l, int r, int i, int j) {
  if(i > r || j < l) return 0;
  if(l >= i && r <= j) return st[p];
  
  int m = (l + r) / 2;
  return query(left(p), l, m, i, j) + query(right(p), m + 1, r, i, j);
}

void update(int p, int l, int r, int pos, int value) {
  if(l == r) st[p] = value;
  else {
    int m = (l + r) / 2;
    if(pos <= m)
      update(left(p), l, m, pos, value);
    else
      update(right(p), m + 1, r, pos, value);
      
    st[p] = st[left(p)] + st[right(p)];
  }
}

int main() {
  
  return 0;
}
