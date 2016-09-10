#include <bits/stdc++.h>
#define MAXN int(1e5+5)
using namespace std;
typedef long long ll;
ll cnt[MAXN];
ll dp[MAXN];

int main()
{
  int n; cin >> n;
  memset(cnt,0,sizeof cnt);
  for(int i = 0 ; i < n ; ++i)
    {
      int k; cin >> k;
      ++cnt[k];
    }
  ll ans = -1;
  dp[1] = cnt[1];
  for(int i = 2 ; i < MAXN ; ++i)
    {
      dp[i] = max(dp[i-1],dp[i-2]+cnt[i]*i);
    }
  for(int i = 0 ; i < MAXN ; ++i)
    ans = max(ans,dp[i]);
  cout << ans << "\n";
  return 0;
}
