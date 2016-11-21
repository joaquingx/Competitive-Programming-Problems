#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
vector<vector < int > > Adj,AdjT;
vector<int> vis,order,cnx,a;

void dfs1(int u)
{
  vis[u]=1;
  for(int v : Adj[u])
    {
      if(!vis[v])
	dfs1(v);
    }
  order.push_back(u);
}

void dfs2(int u)
{
  vis[u] = 1;
  cnx.push_back(u);
  for(int v : AdjT[u])
    {
      if(!vis[v])
	dfs2(v);
    }
}
void initGraph(int n)
{
  Adj.resize(n);
  AdjT.resize(n);
}

int main()
{
  int n,m; cin >> n;
  a.resize(n);
  for(int i = 0 ; i < n; ++i)
    cin >> a[i];
  cin >> m;
  initGraph(n);
  for(int i = 0 ;i < m; ++i)
    {
      int l,r; cin>> l >> r;
      --l,--r;
      Adj[l].push_back(r);
      AdjT[r].push_back(l);
    }
  vis.assign(n,0);
  for(int i = 0 ; i < n; ++i)
    {
      if(!vis[i])
	dfs1(i);
    }
  vis.assign(n,0);
  ll ans=0,ways=1;
  for(int i = 0 ;i < n ; ++i)
    {
      int v = order[n-i-1];
      if(!vis[v])
	{
	  dfs2(v);
	  ll min = MOD; 
	  for(int j = 0 ; j < cnx.size() ; ++j)
	    if(min > a[cnx[j]])
	      min = a[cnx[j]];
	  ans += min;
	  ll cnt=0;
	  for(int j = 0 ; j < cnx.size() ; ++j)
	    {
	      if(min == a[cnx[j]])
		++cnt;
	    }
	  ways = (ways % MOD * cnt % MOD) % MOD;
	  cout << "\n";
	  cnx.clear();
	}	
    }
  cout << ans << " " << ways << "\n";
}
