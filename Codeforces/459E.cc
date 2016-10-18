#include <bits/stdc++.h>
using namespace std;
map<int,int> dp;

void init(int u , int v, int &fst , int &snd)
{
  fst = dp[v];
  snd = dp[u];
  if(dp.count(v) <= 0)
    fst = 0;
  if(dp.count(u) <= 0)
    snd = 0;
}


int main()
{
  ios_base::sync_with_stdio(0);
  vector< pair< int, pair<int,int> > > Adj;
  int n,m;
  scanf("%d %d",&n,&m);
  for(int i = 0 ; i < m ; ++i)
    {
      int x,y,z;
      scanf("%d %d %d", &x,&y,&z);
      Adj.push_back( {z,{x,y} } );
    }
  sort(Adj.begin(), Adj.end());
  int act = Adj[0].first;
  vector< pair<int,int> > save;
  save.push_back({Adj[0].second.second,1});
  save.push_back({ Adj[0].second.first, 0} );
  int fst,snd;
  for(int i = 1 ; i < m ; ++i)
    {
      int u = Adj[i].second.first;
      int v = Adj[i].second.second;
      init(u,v,fst,snd);
      if(Adj[i].first != act)
	{
	  for(int j = 0 ;j < save.size() ; ++j)
	    {
	      int k =  dp[save[j].first];
	      if(dp.count(save[j].first) <= 0 )
		k = 0;
	      dp[save[j].first] = max(k,save[j].second);
	    }
	  save.clear();
	  save.resize(0);
	  init(u,v,fst,snd);
	  dp[v] = max( fst,  snd + 1);
	  act = Adj[i].first;
	}
      else
	{
	  save.push_back({v,  max( fst , snd+1) } );
	}
	
    }
  for(int j = 0 ;j < save.size() ; ++j)
    {
      int k =  dp[save[j].first];
      if(dp.count(save[j].first) <= 0 )
	k = 0;
      dp[save[j].first] = max(k,save[j].second);      
    }
  int ans=-1;
  for(auto it= dp.begin() ; it != dp.end() ; it++)
    {
      ans = max(it->second,ans);
    }
  printf("%d\n",ans);
}
