#include <bits/stdc++.h>
#define MAXN 110
using namespace std;

int main()
{
  int dp[MAXN][3],ans=-1,v[MAXN];
  int n; cin >> n;
  for(int i = 1 ; i <= n; ++i)
    cin >> v[i];
  memset(dp,0,sizeof dp);
  for(int i = 1 ; i <= n ; ++i)
    {
      dp[i][0] = max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
      if(v[i] == 1)
	{
	  dp[i][1] = max(dp[i-1][0],dp[i-1][2]) + 1;
	}
      if(v[i] == 2)
	{
	  dp[i][2] = max(dp[i-1][0],dp[i-1][1]) + 1;
	}
      if(v[i] == 3)
	{
	  dp[i][1] = max(dp[i-1][0],dp[i-1][2]) + 1;
	  dp[i][2] = max(dp[i-1][0],dp[i-1][1]) + 1;
	}
      for(int j = 0 ; j < 3 ; ++j)
	ans = max(ans,dp[i][j]);
    }
  cout << n - ans << "\n";
  return 0;
}
