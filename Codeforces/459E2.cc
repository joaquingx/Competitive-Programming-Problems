#include <bits/stdc++.h>
#define MAXN int(3*1e5+10)
using namespace std;
int dpp[MAXN],dp[MAXN];
vector< pair<int,int> > Adj[MAXN];

int main()
{
  ios_base::sync_with_stdio(0);
  int n,m; scanf("%d %d",&n,&m);
  for(int i = 0 ; i < m ; ++i)
    {
      int x,y,z;
      scanf("%d %d %d",&x,&y,&z);
      Adj[z].push_back( {x,y} );
    }//
  for(int i = 0 ; i < MAXN ; ++i)
    {
      for(int j = 0 ; j < Adj[i].size() ; ++j)
	{
	  int u = Adj[i][j].first; int v = Adj[i][j].second;
	  dpp[v] = 0;
	}
      for(int j = 0 ; j < Adj[i].size() ; ++j)
	{
	  int u = Adj[i][j].first; int v = Adj[i][j].second;
	  dpp[v] = max(dpp[v],dp[u]+1);
	}
      for(int j = 0 ; j < Adj[i].size() ; ++j)
	{
	  int u = Adj[i][j].first; int v = Adj[i][j].second;
	  dp[v] = max(dp[v],dpp[v]);
	}
    }
  int ans =0;
  for(int i =0 ; i < MAXN ; ++i)
    ans = max(ans,dp[i]);
  printf("%d\n",ans);
  return 0;
}
