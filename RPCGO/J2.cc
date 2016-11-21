#include <bits/stdc++.h>
#define MAXN 110
using namespace std;
int dp[MAXN][MAXN][MAXN],matrix[MAXN][MAXN];

int main()
{
  int n,m; cin >> n >> m;
  for(int i = 1  ;i <= m; ++i)
    {
      for(int j = 1 ; j <= n ; ++j)
	cin >> matrix[i][j];
    }
  memset(dp,-1,sizeof dp);
  for(int i = 1 ; i <= m ; ++i)
    {
      dp[1][i][i] = matrix[1][i] ;
    }
  int ans = -1;
  for(int i = 2; i <= m ; ++i )
    {
      for(int j = 1 ; j <= n ; ++j)
	{
	  for(int l = j ; l <= n ; ++l)
	    {
	      for(int k = 1 ; k <= n ; ++k)
		{
		  if(j + k == l)
		    dp[i][j][l] =  max(dp[i-1][j][j] + matrix[i][j] )
		    dp[i][j][j+k] = max(dp[i-1][j][k] + matrix[i][j],dp[i][j][k+j]);
		  ans = max(ans,dp[i][j][j+k]);
		}
	    }
	}
    }
  cout << ans << "\n";
  return 0;
}
