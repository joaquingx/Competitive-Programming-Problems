#include <bits/stdc++.h>
#define MAXN int(1e5+10)
#define INF int(1e9)
using namespace std;
int vis[MAXN];
int dis[MAXN];
vector<int> roots;
void init()
{
  memset(vis,0,sizeof vis);
  for(int i=0 ; i < MAXN ; ++i)
    {
      dis[i] = INF;
    }
}

void bfs(vector< vector<int> > Adj, int s)
{
  vis[s] = 1;
  dis[s] = 0;
  queue<int> Q; Q.push(s);
  while(!Q.empty())
    {
      int u = Q.front(); Q.pop();
      for(int v : Adj[u])
	{
	  if(vis[v] == 0)
	    {
	      vis[v] =1;
	      dis[v] = dis[u] + 1;
	      Q.push(v);
	    }
	}
    }
}

int main()
{
  vector< vector<int > > Adj;
  int n; cin >> n;
  Adj.resize(n);
  for(int i =  0 ; i < n ; ++i)
    {
      int x ; cin >> x;
      if(x != -1)
	{
	  --x;
	  Adj[x].push_back(i);
	}
      else
	roots.push_back(i);
    }
  init();
  for(int i = 0 ; i < roots.size() ; ++i)
    {
      bfs(Adj,roots[i]);
    }
  int ans = -1;
  for(int i = 0 ;i < n ; ++i)
    {
      if(dis[i] != INF)
	ans = max(ans,dis[i]+1);
    }
  cout << ans << "\n";
  return 0;

}
