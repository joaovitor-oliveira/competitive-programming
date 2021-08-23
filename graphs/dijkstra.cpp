#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

typedef pair<int, int> ii;
typedef vector<ii> vii;

const int MAXN = (int)1e4 + 5;

int v;
vii graph[MAXN];
int dist[MAXN];

int dijkstra(int s, int d) {
  for(int i = 0; i < v; i++)
    dist[i] = INF;
    
  dist[s] = 0;
  priority_queue<ii, vector<ii> , greater<ii> > pq;
  pq.push(ii(dist[s], s));
  
  while(!pq.empty()) {
    ii front = pq.top();
    pq.pop();
    
    int d = front.first;
    int u = front. second;
    
    if(d > dist[u]) continue;
    
    for(auto node : graph[u]) {
      if(dist[u] + node.second < dist[node.first]) {
        dist[node.first] = dist[u] + node.second;
        pq.push(ii(dist[node.first], node.first));
      }
    }
  }
  
  return dist[d];
}

int main() {
  int e, x, y, z;
  scanf("%d %d", &v, &e);

  while(e--) {
    scanf("%d %d %d", &x, &y, &z);
    graph[x].push_back(ii(y, z));
    graph[y].push_back(ii(x, z));
  }
  
  int ans = dijkstra(0, v - 1);
  printf("%d\n", ans != INF ? ans : -1);
  
  return 0;
}
