#include <bits/stdc++.h>
#define MAXN 5010
using namespace std;
typedef long long ll;
ll dp[MAXN][MAXN];
ll sum[MAXN];


int main()
{
  sum[0] = 0;
  memset(dp,0,sizeof dp);
  int n,m,k;  cin >> n >> m >> k;
  for(int i = 1 ; i <= n ; ++i)
    {
      ll r; cin >> r;
      sum[i] = r + sum[i-1];
    }

  for(int i = m ; i <= n ; ++i)
    {
      for(int j = 1 ; j <= k ; ++j)
	{
	  dp[i][j] = max(dp[i-1][j], dp[i-m][j-1] + sum[i] - sum[i-m]);
	}
    }
  cout << dp[n][k] << "\n";
}
