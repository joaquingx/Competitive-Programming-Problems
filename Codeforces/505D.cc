#include <bits/stdc++.h>
using namespace std;
vector<vector < int > > Adj,AdjT,AdjN,component;
vector<int> order,cnx;
map<int,int> vis;
int cc=0;

void dfs0(int u)
{
  component[cc].push_back(u);
  vis[u] = 1;
  for(int v : AdjN[u])
    {
      if(vis.count(v) == 0)
	dfs0(v);
    }  
}

void dfs1(int u)
{
  vis[u]=1;
  for(int v : Adj[u])
    {
      if(vis.count(v) == 0)
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
      if(vis.count(v) == 0)
	dfs2(v);
    }
}
void initGraph(int n)
{
  Adj.resize(n);
  AdjT.resize(n);
  AdjN.resize(n);
  component.resize(n);
}

int main()
{
  int n,m; cin >> n >> m ;
  initGraph(n);
  for(int i = 0 ;i < m; ++i)
    {
      int l,r; cin>> l >> r;
      --l,--r;
      Adj[l].push_back(r);
      AdjT[r].push_back(l);

      AdjN[l].push_back(r);
      AdjN[r].push_back(l);
    }
  
  vis.clear();
  for(int i = 0 ; i < n; ++i)
    {
      if(vis.count(i) == 0)
  	{
  	  dfs0(i); 
  	  ++cc;
  	}
    }
  int ans=0,cnt;
  for(int i= 0 ; i < cc ; ++i)
    {
      vis.clear();
      for(int v : component[i])
  	{
	  if(vis.count(v) == 0)
  	    dfs1(v);
  	}
      vis.clear();
      bool cycle=0;
      for(int j = order.size() - 1 ; j >= 0 ; --j)
  	{
  	  int v = order[j];
	  if(vis.count(v) == 0)
  	    {
  	      dfs2(v);
	      if(cnx.size() >= 2)
		cycle=1;
  	      cnx.clear();
  	    }	
  	}
      if(cycle)
	ans += component[i].size();
      else
	ans += component[i].size() - 1;
      order.clear();
    }
  cout << ans << "\n";
}
