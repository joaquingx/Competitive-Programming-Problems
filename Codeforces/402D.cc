#include <bits/stdc++.h>
#define MAXN 5010
#define INF int(2*1e9)
using namespace std;
int arr[MAXN],bad[MAXN],gcda[MAXN],n,m,dp[MAXN][MAXN],fnc[MAXN],fnc2[MAXN];

void initGcda()
{
  gcda[0] = arr[0];
  for(int i = 1 ; i < n ; ++i)
    gcda[i] = __gcd(gcda[i-1],gcda[i]);
}

int f(int x)
{
  int ans=0;
  if(x==0) return 0;
  while(x != 1)
    {
      int i = 2;
      for( ; i * i <= x ; ++i)
	{
	  if(x%i == 0)
	    {
	      bool tt=1;
	      for(int j = 0 ; j < m; ++j)
		if(i == bad[j])
		  tt=0;
	      if(tt) ans++; else ans--;
	      x/=i;
	      break;
	    }
	}
      if(i*i > x)
	{
	  bool tt=1;
	  for(int j = 0 ; j < m; ++j)
	    if(x == bad[j] )
	      tt=0;
	  if(tt) ans++; else ans--;
	  x = 1;
	}
    }
  return ans;
}


int solve(int i , int j)
{
  // if(i == 0)
  //   {
  //     // cout << "llego\n";
  //     dp[i][j] = max(fnc[i],fnc[i] - fnc2[i]*i + fnc2[j]*i);
  //     return dp[i][j];
  //   }
  if(dp[i][j] != -INF)
    {
      return dp[i][j];
    }
  // cout << arr[i] << " : "<<f(arr[i]) << "\n";
  dp[i][j] = max(solve(i-1,j) + fnc[i]
		 , solve(i-1,i) + fnc[i] - fnc2[i]*i + fnc2[j]*i );
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 0 ; i < n ; ++i)
    cin >> arr[i];
  for(int i = 0 ; i < m ; ++i)
    cin >> bad[i];
  arr[n] = 1;
  n++;
  initGcda();
  for(int i = 0 ;i < MAXN; ++i)
    for(int j = 0 ; j < MAXN; ++j)
      dp[i][j] = -INF;
  for(int i= 0 ;i < n ; ++i)
    fnc[i] = f(arr[i]);
  for(int i= 0 ;i < n ; ++i)
    fnc2[i] = f(gcda[i]);
  solve(n-1,n-1);
  int ans = -INF;
  for(int i= 0; i < n ; ++i)
    ans = max(ans,dp[0][i]);
  cout << ans << "\n";
  return 0;

}
