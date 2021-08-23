#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 0x3F3F3F3F
#define ii pair<int,int>

vector<ii> adj[40000];
int V;

int prim()
{
	int ans = 0;
	
	int d;
	bool visitados[V];
	int dist[V];
	priority_queue <ii, vector<ii>, greater<ii> > fila;
	
	for(int i = 0; i < V; i++)
	{
		visitados[i] = false;
		dist[i] = INF;
	}
	
	dist[0] = 0;
	fila.push(ii(0,0));
	
	while(!fila.empty())
	{
		ii top = fila.top();
		fila.pop();
		int u = top.second, d = top.first;
		if(!visitados[u])
		{
			ans += d;
			visitados[u] = true;
			for(int i = 0; i < adj[u].size(); i++)
			{
				int v =adj[u][i].first;
				int custo = adj[u][i].second;
				if(!visitados[v] && (dist[v] > custo))
				{
					dist[v] = custo;
					fila.push(ii(dist[v], v));
				}
			}
		}
	}
	
	return ans;
}

int main() {
  
  return 0;
}
