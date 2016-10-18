#include <bits/stdc++.h>
using namespace std;
#define MAXN int(1e5+10)
int cnt=0,n,m,a[MAXN],vis[MAXN],cats[MAXN],trace[MAXN];
vector< vector<int> > Adj;

void init()
{
  memset(vis,0,sizeof vis);
  memset(cats,0,sizeof cats);
  memset(a,0,sizeof a);
}


void bfs(int s)
{
  vis[s] = 1;
  cats[s] = a[s];
  trace[s] = a[s];
  queue<int> Q;
  Q.push(s);
  while(!Q.empty())
    {
      int u = Q.front(); Q.pop();
      bool isleaf = 1;
      for(int v : Adj[u])
	{
	  if(!vis[v])
	    {
	      isleaf=0;
	      if(a[v] == 0)
		trace[v] = 0;
	      else{
		if(a[u] > 0 )
		  trace[v] = trace[u] + a[v];
		else
		  trace[v] = a[v];
	      }
	      cats[v] = max(cats[u],trace[v]);
	      vis[v] = 1;
	      Q.push(v);
	    }
	}
      if(isleaf && cats[u] <= m)
	{
	  ++cnt;
	}
    }
}

int main()
{
  init();
  cin >> n >> m;
  Adj.resize(n);
  for(int i = 0 ; i < n ; ++i)
    cin >> a[i];
  for(int i = 1 ; i <= n-1 ; ++i)
    {
      int l,r; cin >> l >> r;
      --l;--r;
      Adj[l].push_back(r);
      Adj[r].push_back(l);
    }
  bfs(0);
  cout << cnt << "\n";
  return 0;
}
