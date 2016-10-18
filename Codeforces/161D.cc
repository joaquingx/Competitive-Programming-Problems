#include <bits/stdc++.h>
#define MAXN int(1e5)
using namespace std;
int vis[MAXN];
int dis[MAXN];
void bfs(vector< vector< int > > Adj , int s)
{
  memset(vis,0,sizeof vis);
  vis[s] = 1;
  dis[s] = 0;
  queue<int> Q ;Q.push(s); 
  while(!Q.empty())
    {
      int u = Q.front(); Q.pop();
      for(int v : Adj[u])
	{
	  if(vis[v] == 0)
	    {
	      vis[v] = 1;
	      dis[v] = dis[u] + 1;
	      Q.push(v);
	    }
	}
    }
}

int main()
{
  vector< vector<int > > Adj;
  int n,k; cin >> n >> k;
  Adj.resize(n);
  for(int i=0 ; i < n -1 ; ++i)
    {
      int x , y ; cin >> x >> y;
      --x;--y;
      Adj[x].push_back(y);
      Adj[y].push_back(x);
    }
  bfs(Adj,s);
  for(int i = 0 ; i < n; ++i)
    {
      for()
    }
  return 0;
}
