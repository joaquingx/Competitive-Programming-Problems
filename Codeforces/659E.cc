#include <bits/stdc++.h>
using namespace std;
#define MAXN int(1e5+1)
int cnt;
int vis[MAXN];
bool cycle;
vector < vector < int > > Adj;

void dfs(int p,int u)
{
  vis[u] = 1;
  for(int v : Adj[u])
    {
      if(vis[v] == 0)
	{
	  dfs(u,v);
	}
      else
	{
	  if(v != p)
	    cycle = 1;
	}
    }
}

// void bfs(vector< vector<int> > Adj, int s)
// {
//   vis[s] = 1;
//   dis[s] = 0;
//   queue<int> Q; Q.push(s);
//   while(!Q.empty())
//     {
//       ++cnt;
//       int u = Q.front(); Q.pop();
//       for(int v : Adj[u])
// 	{
// 	  if(vis[v] == 0)
// 	    {
// 	      vis[v] =1;
// 	      Q.push(v);
// 	    }
// 	}
//     }
// }


int main()
{
  int n,m; cin >> n >> m;
  Adj.resize(n);
  for(int i = 0; i < m ; ++i)
    {
      int x,y ; cin >> x >> y;
      --x;--y;
      Adj[x].push_back(y);
      Adj[y].push_back(x);
    }
  memset(vis,0 , sizeof vis);
  int ans =0;
  for(int i= 0 ; i < n ; ++i)
    {
      if(vis[i] == 0)
	{
	  cycle=0;
	  dfs(-1,i);
	  if(!cycle)
	    {
	      ++ans;
	    }
	}
    }
  cout << ans << "\n";
  return 0;
}
