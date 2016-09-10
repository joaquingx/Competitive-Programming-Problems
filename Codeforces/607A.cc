#include <bits/stdc++.h>
#define MAXN int(1e6+1)
using namespace std;
int x[MAXN],p[MAXN],dp[MAXN];

int main()
{
  memset(p,0,sizeof p);
  memset(dp,0,sizeof dp);
  int n,ans=-1; cin >> n;
  for(int i = 0 ; i < n ; ++i)
    {
      int k ; cin >> x[i] >> k;
      p[x[i]] = k;
    }
  // for(int i = 0 ; i < n ; ++i)
  //   {
  //     cout << p[i] << "\n";
  //   }
  if(p[0] > 0)
    dp[0] = 1;
  for(int i= 1 ; i < MAXN ; ++i)
    {
      if(p[i] == 0)
	{
	  dp[i] = dp[i-1];
	}
      else
	{
	  if(i -p[i] - 1 < 0)
	    dp[i] = 1;
	  else dp[i] = dp[i-p[i]-1] + 1;
	}
      ans = max(dp[i],ans);
    }
  cout << n-ans << "\n";
}
