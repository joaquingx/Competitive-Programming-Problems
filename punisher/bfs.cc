#include <bits/stdc++.h>
using namespace std;
vector<vector <int> > Adj;
vector<int> d,vis,parent;

void bfs(int s)
{
  queue<int> cola;
  d[s] = 0;
  vis[s] = 1;
  cola.push(s);
  while( !cola.empty() )
    {
      int u = cola.front(); cola.pop();
      for(int i = 0 ; i < Adj[u].size() ; ++i )
	{
	  int v = Adj[u][i];
	  if(vis[v] == 0)
	    {
	      parent[v] = u;
	      d[v] = d[u] + 1;
	      vis[v] = 1;
	      cola.push(v);
	    }
	}
    }
}

void dfs(int s)
{
  vis[s] = 1;
  for(int i = 0 ; i < Adj[s].size() ; ++i)
    {
      int v = Adj[s][i];
      if(vis[v] == 0)
	{
	  parent[v] = s;
	  dfs(v);
	}
    }
}



int main()
{
  int n,m; cin >> n >> m;
  Adj.resize(n); d.resize(n,0)  ; vis.resize(n,0); parent.resize(n,-1);
  for(int i = 0 ; i < n ; ++i)
    {
      int a,b ; cin >> a >> b;
      Adj[a].push_back(b);
      Adj[b].push_back(a);
    }
  dfs(0);
  //bfs(0);
  for(int i = 0 ; i < n ; ++i){
    cout <<  i << " " << " vis: " << vis[i] << " distancia : " <<d[i] << " padre: " << parent[i] << "\n";
  }
  return 0;
}
