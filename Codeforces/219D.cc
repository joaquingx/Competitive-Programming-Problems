#include <bits/stdc++.h>
#define MAXN int(2e5+10)
using namespace std;
vector < vector < pair< int , int > > > Adj;
int dp[MAXN],vis[MAXN];

void calc(int u,int p)
{
  vis[u] = 1;
  for(int i = 0 ;i < Adj[u].size() ; ++i)
    {
      if(Adj[u][i].first != p)
	dp[u] += Adj[u][i].second;
    }
  for(int i = 0 ;i < Adj[u].size() ; ++i)
    {
      int v = Adj[u][i].first, dir = Adj[u][i].second;
      if(!vis[v])
	{
	  calc(v,u);
	  dp[u] += dp[v];
	}
    }
}

void calc2(int u,int p, int car)
{
  vis[u]=1;
  int sum = dp[u];
  if(p != -1)
    {
      if(!car)
	{
	  dp[u] += 1 + dp[p] - dp[u];
	}
      else
	{
	  dp[u] += dp[p] - dp[u] - 1;
	}
    }
  for(int i = 0 ; i < Adj[u].size() ; ++i)
    {
      int v = Adj[u][i].first, dir = Adj[u][i].second;
      if(!vis[v])
	calc2(v,u,dir);
    }
}

int main()
{
  int n; cin >> n;
  Adj.resize(n);
  for(int i = 0 ;i < n-1; ++i)
    {
      int l,r; cin >> l >> r;
      --l,--r;
      Adj[l].push_back({ r , 0 });
      Adj[r].push_back({ l , 1 } );      
    }
  memset(dp,0,sizeof dp);
  memset(vis,0,sizeof vis);
  calc(0,-1);
  // for(int  i = 0 ;i < n ; ++i)
  //   cout << dp[i] << " ";
  // cout << "\n";
  memset(vis,0,sizeof vis);
  calc2(0,-1,-1);
  // for(int  i = 0 ;i < n ; ++i)
  //   cout << dp[i] << " ";
  // cout << "\n";
  int mini = *min_element(dp , dp + n);
  // cout << mini << "\n";
  // int cc = count(dp ,dp + n,mini);
  cout << mini << "\n";
  for(int i = 0 ; i < n ; ++i)
    if(dp[i] == mini)
      cout << i+1 << " ";
  cout << "\n";
  return 0;
}
