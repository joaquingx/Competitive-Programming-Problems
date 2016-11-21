#include <bits/stdc++.h>
using namespace std;
vector<int> p,rating,vis,dis;
vector< vector< int > > m,m2;
vector< vector < pair < int, int > > > Adj;
vector < pair < int , pair < int , int > > > aristas;

void dsuCreate(int u)
{
  p[u] = u;
  rating[u] = 0;
}

int dsuFind(int v)
{
  return (v == p[v] ? v : p[v] = (dsuFind(p[v]) ) );
}

void dsuUnion(int u , int v)
{
  u = dsuFind(u);
  v = dsuFind(v);
  if(rating[u] > rating[v])
    p[v] = u;
  else
    if(rating[u] == rating[v])
      {
  	p[u] = v;
  	++rating[u];
      }
    else
      p[u] = v;  
}


void initdfs(int n)
{
  vis.assign(n,0);
  dis.assign(n,0);
}

void dfs(int u,int p,int w)
{
  vis[u] = 1;
  if(p == -1) dis[u] = 0;
  else dis[u] = dis[p] + w;
  for(int i = 0 ; i < Adj[u].size() ; ++i)
    {
      int v = Adj[u][i].first, ww = Adj[u][i].second;
      if(!vis[v])
	dfs(v,u,ww);
    }  
}

void init(int n)
{
  m.resize( n , vector<int>(n,0) ) ;
  m2.resize( n , vector<int>(n,0) ) ;
  Adj.resize(n);
  p.resize(n);
  rating.resize(n);
}

bool allzeros(int n)
{
  for(int i= 0 ;i < n ; ++i)
    for(int j = 0 ; j < n; ++j)
      if(m[i][j] != 0)
	return 0;
  return 1;
}

int main()
{
  ios_base::sync_with_stdio(0);
  // cin.tie(NULL);
  int n; scanf("%d",&n);
  init(n);
  for(int i = 0 ; i < n; ++i)
    for(int j = 0 ; j < n ; ++j)
      {
	scanf("%d",&m[i][j]);
	aristas.push_back( {m[i][j] , {i,j} });
      }
  if(allzeros(n) and n > 1) { printf("NO\n"); return 0;};
  sort(aristas.begin() , aristas.end()) ;
  for(int i = 0 ; i < n; ++i)
    dsuCreate(i);
  for(int i = 0 ;i < aristas.size() ; ++i)
    {
      int weight  =  aristas[i].first , to = aristas[i].second.first , from = aristas[i].second.second;      
      if(dsuFind(to) != dsuFind(from))
  	{
  	  dsuUnion(to,from);
  	  Adj[to].push_back({from,weight});
  	  Adj[from].push_back({to,weight});
  	}
    }
  for(int i = 0 ; i < n ; ++i)
    {
      initdfs(n);
      dfs(i,-1,0);
      for(int j = 0 ; j < n; ++j)
      	m2[i][j] = dis[j];
    }
  bool is=1;
  for(int i = 0 ;i < n ; ++i)
    for(int j = 0 ; j < n; ++j)
      {
  	if(m[i][j] != m2[i][j])
  	  is=0;
      }
  if(is)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
