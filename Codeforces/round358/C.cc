#include <bits/stdc++.h>
#define MAXN int(1e5+10)
using namespace std;
typedef long long ll;
int mark[MAXN],vis[MAXN];
ll valor[MAXN],carga[MAXN];
vector< vector< pair< int, ll > > > Adj;

int bfs(int u)
{
  int ans=0;
  memset(vis,0,sizeof vis);
  memset(carga,0,sizeof carga);
  memset(mark,0,sizeof mark);
  vis[u] = 1;
  queue<int> Q;
  Q.push(u);
  while(!Q.empty())
    {
      int u = Q.front(); Q.pop();
      for(int i = 0 ; i < Adj[u].size() ; ++i)
	{
	  int v = Adj[u][i].first;
	  ll cost = Adj[u][i].second;
	  if(!vis[v])
	    {
	      vis[v] = 1;
	      Q.push(v);
	      carga[v] = max(carga[u] + cost, ll(0));
	      if(mark[u])
		{
		  mark[v] = 1;
		  ++ans;
		}
	      else if(carga[v] > valor[v])
		{
		  mark[v] = 1 ;
		  ++ans;
		}
	    }
	}
    }
  return ans;
}


int main()
{
  int n , m ; cin >> n ;
  Adj.resize(n);
  for(int i = 0 ;i < n ; ++i)
    cin >> valor[i];
  for(int i = 0 ; i < n -1; ++i)
    {
      int l;ll r; cin >> l >> r;
      --l;
      Adj[i+1].push_back({l,r});
      Adj[l].push_back({i+1,r});
    }
  cout << bfs(0) << "\n";
  return 0;
}
