#include <bits/stdc++.h>
#define MAXN 110
using namespace std;
typedef long long ll;
#define INF ll(1e15+10) 
ll dp[MAXN][MAXN][MAXN], v[MAXN] , p[MAXN][MAXN];


int main()
{
  int n,m,k; cin >> n >> m >> k;
  for(int i = 0 ;i < n ; ++i)
    cin >> v[i];
  for(int i = 0 ; i < n ; ++i)
    for(int j = 1 ; j <= m ; ++j)
      {
	cin >> p[i][j];
      }
  for(int i= 0 ; i < MAXN ; ++i)
    for(int j= 0 ; j < MAXN ; ++j)
      for(int l= 0 ; l < MAXN ; ++l)
	dp[i][j][l]  = INF;

  if(v[0] == 0)
    for(int i = 1 ; i <= m ; ++i)
      {
	dp[0][i][1] = min(p[0][i],dp[0][i][1]);
	// cout << "arbol :" << 0 << " tam " << 1  <<" color " << i << " " <<dp[0][i][1] << "\n";
      }
  else
    dp[0][v[0]][1]  = 0;

  for(int i = 1 ; i < n ; ++i)
    {
      for(int j = 1 ; j <= m ; ++j)
	{
	  for(int l = 1 ; l <= k; ++l)
	    {
	      if(v[i] == 0)
		{
		  dp[i][j][l] = min(dp[i-1][j][l] + p[i][j] , dp[i][j][l]);
		  for(int f = 0 ; f <= m ; ++f)
		    {
		      if(f != j)
			dp[i][j][l] = min(dp[i][j][l],dp[i-1][f][l-1] + p[i][j]);
		    }
		}
	      else
		{
		  dp[i][v[i]][l] =  min(dp[i-1][v[i]][l],dp[i][v[i]][l]);
		  for(int f = 0 ; f <= m ; ++f)
		    {
		      if(f != v[i])
			dp[i][v[i]][l] = min(dp[i][v[i]][l],dp[i-1][f][l-1]);
		    }
		}
	      // cout << "arbol :" << i << " tam " << l  <<" color " << j << " " <<dp[i][j][l] << "\n";
	    }
	}

    }
  ll ans = INF;
  for(int i = 0 ; i <= m ; ++i)
    {
      // cout << "color :" << i << " "<<dp[n-1][i][k] << "\n";
      ans = min(ans,dp[n-1][i][k]);
    }
  if(ans >= INF) cout << "-1\n";
  else
    cout << ans << "\n";
  return 0;
}
