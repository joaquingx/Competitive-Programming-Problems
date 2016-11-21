#include <bits/stdc++.h>
#define MAXN int(1e4+10)
using namespace std;
vector<vector < int > > Adj,AdjT;
vector<int> vis,order,cnx;
map<string,int> mapa;

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
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  bool flag = 1;
  string cad1,cad2;
  char carac;
  int n,m;
  initGraph(MAXN);
  int cnt = 0;
  cin >> n;
  for(int i = 0 ;i < n; ++i)
    {
      cin >> cad1 >> carac >> cad2;
      if(mapa.find(cad1) == mapa.end())
	{
	  mapa[cad1] = cnt;
	  ++cnt;
	}
      if(mapa.find(cad2) == mapa.end())
	{
	  mapa[cad2] = cnt;
	  ++cnt;
	}
      int l = mapa[cad1],r = mapa[cad2];
      if(carac == '<')
	swap(l,r);
      // cout << l << " " << r << "\n";
      Adj[l].push_back(r);
      AdjT[r].push_back(l);
    }
  vis.assign(MAXN,0);
  for(int i = 0 ; i < cnt; ++i)
    {
      if(!vis[i])
	dfs1(i);
    }
  vis.assign(MAXN,0);
  for(int i = 0 ;i < cnt ; ++i)
    {
      int v = order[cnt-i-1];
      if(!vis[v])
	{
	  dfs2(v);
	  // cout << "Strongly Connected Component\n";
	  // for(int j = 0 ; j < cnx.size() ; ++j)
	  //   cout << cnx[j] << " ";
	  // cout << "\n"	  ;
	  if(cnx.size() > 1)
	    {
	      flag = 0;
	    }
	  cnx.clear();
	}	
    }
  if (!flag)
    cout << "impossible\n";
  else
    cout << "possible\n";
}

