#include <bits/stdc++.h>
using namespace std;
vector<vector <int > > Adj;
vector<int> color,vc[2];


int bfs(int s)
{
  queue<int> cola;
  color[s] = 0;
  vc[0].push_back(s);
  cola.push(s);
  while(!cola.empty())
    {
      int u =  cola.front(); cola.pop();
      for(int i = 0 ; i < Adj[u].size() ; ++i)
	{
	  int v = Adj[u][i];
	  if(color[v] == -1)
	    {
	      color[v] = 1 - color[u];
	      vc[color[v]].push_back(v);
	      cola.push(v);
	    }
	  else if(color[v] == color[u])
	    {
	      return 0;
	    }
	}
    }
  return 1;
}



int main()
{
  bool is = 1;
  int n,m; cin >> n >> m;
  int centroid=-1;
  Adj.resize(n);color.resize(n,-1);
  for(int i = 0 ; i < m ; ++i)
    {
      int a , b ; cin >> a >> b;
      --a;--b;
      Adj[a].push_back(b);
      Adj[b].push_back(a);
    }
  for(int i = 0 ; i < n ; ++i)
    {
      if(Adj[i].size() == 0) continue;
      if(color[i] == -1)
	{
	  if(!bfs(i))
	    {
	      cout << -1 << "\n";
	      return 0;
	    }
	}
    }
  for(int i = 0 ; i < 2 ; ++i)
    {
      cout << vc[i].size() << "\n";
      for(int j = 0 ; j < vc[i].size() ; ++j)
	{
	  cout << vc[i][j] + 1<< " ";
	}
      cout << "\n";
    }
  return 0;
}
