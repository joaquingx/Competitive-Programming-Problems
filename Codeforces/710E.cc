#include <bits/stdc++.h>
#define MAXN int(1e7+10)
using namespace std;
typedef unsigned long long ll;
ll dp[MAXN];


int main()
{
  ios_base::sync_with_stdio(0);
  ll n,x,y; cin >> n >> x >> y;
  dp[0] = 0;
  dp[1] = x;
  for(int i = 2 ; i <= n ; ++i)
    {
      if(i % 2 == 0)
	{
	  dp[i] = min(dp[i-1] + x, dp[i/2] + y);
	}
      else
	{
	  dp[i] = min( dp[i-1] + x , dp[(i+1)/2]+y+x);
	}
// cout << i << " : " << dp[i] << "\n";
    }
  cout << dp[n] << "\n";
  return 0;
}
