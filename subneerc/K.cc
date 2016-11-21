#include <bits/stdc++.h>
#define MAXN int(2*1e5+100)
using namespace std;
int n,m,l,r;
vector< vector<int> > Adj,UAdj,cnx;
vector< pair< int , vector< int > > > rpta;
vector<int> topo,ans;
set< pair<int,int > >  edges;
set< int > segment,aux;
map<int, pair<int,int> > local;
vector<int> nuevo;
int vis[MAXN];

void dfs(int u)
{
  vis[u]= 1;
  for(int v : Adj[u])
    if(!vis[v])
      dfs(v);
  topo.push_back(u);
}

void dfsp(int u,int cnt)
{
  cnx[cnt].push_back(u);
  vis[u] = 1;
  for(int v : UAdj[u])
    if(!vis[v])
      dfsp(v,cnt);
}

int main()
{
  ios_base::sync_with_stdio(0);
  scanf("%d %d",&n,&m);
  Adj.resize(n+1);
  rpta.resize(n+1);
  cnx.resize(n+1);
  UAdj.resize(n+1);
  for(int i = 0 ; i < m ; ++i)
    {
      scanf("%d %d",&l,&r);
      --l;--r;
      edges.insert({l,r});
    }
  for(auto it = edges.begin() ; it != edges.end() ; ++it)
    {
      Adj[it->first].push_back(it->second);
      UAdj[it->first].push_back(it->second);
      UAdj[it->second].push_back(it->first);
    }
  memset(vis,0 , sizeof vis);
  for(int i = 0 ;i < n ; ++i)
    {
      if(!vis[i])
	dfs(i);
    }
  int cnt=0;
  memset(vis,0 , sizeof vis);
  for(int i = 0 ;i < n ; ++i)
    {
      if(!vis[i])
	{
	  dfsp(i,cnt);
	  ++cnt;
	}
    }
  // cout << cnt << "\n";
  reverse(topo.begin(),topo.end());
  nuevo = topo;
  memset(vis,0,sizeof vis);
  for(int i = 0 ;i < cnt ; ++i)
    {
      topo.clear();
      ans.clear();
      for(int vertices : cnx[i])
  	{
  	  if(!vis[vertices])
  	    dfs(vertices);
  	}
      reverse(topo.begin(),topo.end());
      int idx = topo[0];
      aux.insert(idx);
      for(int v : Adj[idx])
  	segment.insert(v);
      for(int j = 1 ;j < topo.size() ; ++j)
  	{
  	  int indice = topo[j];
  	  if(segment.find(indice) != segment.end())
  	    {
  	      while(!segment.empty())
  		{
  		  segment.erase(segment.begin());
  		}
	      while(!aux.empty())
		{
		  ans.push_back(*(aux.begin()));
		  aux.erase(aux.begin());
		}
  	    }
	  aux.insert(indice);
  	  for(int v : Adj[indice])
  	    segment.insert(v);
  	}
      while(!segment.empty())
  	{
  	  segment.erase(segment.begin());
  	}
      while(!aux.empty())
	{
	  ans.push_back(*(aux.begin()));
	  aux.erase(aux.begin());
	}
      rpta[i].first = 0;
      for(int j = 0 ; j < ans.size() ; ++j)
  	{
	  // cout << ans[j] << "--";
  	  local[ans[j]] = {i,j};
  	  rpta[i].second.push_back(ans[j]);
  	}
      // cout << "\n";
    }
  int comp,hasta;
  for(int i = 0 ; i < n ; ++i)
    {
      comp = local[i].first;
      hasta = local[i].second;
      // cout << comp << " "  << hasta << "\n";
      if(hasta >= rpta[comp].first)
  	for(int j = rpta[comp].first ; j <= hasta ; ++j)
  	  {
	    printf("%d ",rpta[comp].second[j]+1); 
  	    ++rpta[comp].first;
  	  }
    }
  printf("\n");
  return 0;
}
