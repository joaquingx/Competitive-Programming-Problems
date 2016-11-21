#include <bits/stdc++.h>
#define MAXN 120
using namespace std;
int dp[MAXN][ MAXN * MAXN ]; // N Botellas, C Capacidad
pair<int,int> a[MAXN];

int main()
{
  int n,cnt=0; cin >> n;
  for(int i = 0 ;i < n; ++i)
    {
      cin >> a[i].first;
      cnt += a[i].first;
    }
  for(int i = 0 ; i < n ; ++i)
    {
      cin >> a[i].second;
    }
  memset(dp,-1, sizeof dp );
  dp[0][0] = 0;
  for(int i = 0 ; i < n ; ++i)
    {
      for(int j = n-1 ; j >= 0 ; --j)
	{
	  for(int k = 0 ; k <= MAXN * MAXN ; ++k)
	    if(dp[j][k] >= 0) // existe
	      dp[j+1][k + a[i].second] =  max (dp[j+1][k + a[i].second] , dp[j][k] + a[i].first);
	}
      // cout << i << ": " << "\n";
      // for(int j = 1 ; j <= n ; ++j)
      // 	{
      // 	  for(int k = 1 ; k <= 30 ; ++k)
      // 	    cout << dp[j][k] << " ";
      // 	  cout << "\n";
      // 	}
      // cout << "\n";
	
    }
  for(int j = 1 ; j <= n ; ++j)
    {
      int ans=-1;
      for(int i = cnt ; i <= MAXN * MAXN ; ++i)
	{
	  if(dp[j][i] >= 0)
	    {
	      ans = max(ans,dp[j][i]);
	    }	  
	}
      if(ans > -1)
	{
	  cout << j << " " << cnt - ans << "\n";
	  return 0;
	}
    }
  return 0;
}
