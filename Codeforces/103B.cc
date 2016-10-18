#include <bits/stdc++.h>
#define MAXN int(1e5+10)
using namespace std;
int vis[MAXN];


void bfs(vector<vector < int > > Adj , int s)
{
  vis[s] = 1;
  queue<int> Q; Q.push(s);
  while(!Q.empty())
    {
      int u = Q.front(); Q.pop();
      for(auto v : Adj[u])
	{
	  if(vis[v] == 0)
	    {
	      vis[v] = 1;
	      Q.push(v);
	    }
	}
    }
}


int main()
{
  vector< vector<int> >  Adj;
  int n,m;cin >> n >> m;
  Adj.resize(n);
  memset(vis,0,sizeof vis);
  for(int i = 0 ; i < m ; ++i)
    {
      int x,y; cin >> x >> y ;
      --x;--y;
      Adj[x].push_back(y);
      Adj[y].push_back(x);
    }
  int cnx = 0;
  for(int i = 0 ;i  < n ; ++i)
    {
      if(vis[i] == 0) 
	{
	  bfs(Adj,i);
	  ++cnx;
	}
    }
  if(cnx == 1)
    {
      if(n == m)
	cout << "FHTAGN!\n";
      else
	cout << "NO\n";
    }
  else
    cout << "NO\n";
}
