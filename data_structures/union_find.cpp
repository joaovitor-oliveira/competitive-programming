#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int)1e5 + 5;

int;
int pai[MAXN], rank[MAXN];

int find(int x) {
  return (pai[x] == x) ? x : (pai[x] = find(pai[x]));
}

bool in(int i, int j) {
  return find(i) == find(j);
}

void join(int i, int j) {
  if(!in(i, j)) {
    int x = find(i);
    int y = find(j);
    
    if(rank[x] > rank[y])
      pai[y] = x;
    else {
      pai[x] = y;
      if(rank[x] == rank[y])
        rank[y]++;
    }
  }
}

void init() {
  for(int i = 0; i < n; i++) {
    pai[i] = i;
    rank[i] = 1;
  }
}

int main(){
  
  return 0;
}
