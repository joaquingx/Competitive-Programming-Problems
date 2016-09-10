#include <bits/stdc++.h>
#include <stdio.h>
#define MAXN int(3*1e5+10)
#define MOD 4
typedef long long ll;
using namespace std;

ll dp[MAXN][4];

int cnv(char a)
{
  return a-'0';
}

int main()
{
  ios_base::sync_with_stdio(0);
  ll ans = 0;
  char pat[MAXN];
  memset(dp,0,sizeof dp);
  memset(pat,0,sizeof pat);
  scanf("%s",pat);
  dp[0][cnv(pat[0])%MOD]=1;
  ans += dp[0][0];
  for(int i = 1 ; i < MAXN ; ++i)
    {
      if(pat[i] == 0)
	break;
      for(int j = 0 ; j < 4 ; ++j)
  	{
	  if(dp[i-1][j] > 0)
	    {
	      int res = j*10 + cnv(pat[i]);
	      res %= MOD;
	      // cout << res << "\n";
	      dp[i][res]+= dp[i-1][j];
	    }
  	}
      ++dp[i][cnv(pat[i])%MOD];
      ans += dp[i][0];
    }
  printf("%I64d\n",ans);
  return 0;
}
