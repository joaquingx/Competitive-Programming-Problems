#include <bits/stdc++.h>
#define MAXN int(1e5+10)
using namespace  std;
int f[MAXN],b[MAXN],cnt[MAXN],re[MAXN];

int main()
{
  ios_base::sync_with_stdio(0);
  memset(f,-1,sizeof f);
  memset(cnt, -1, sizeof cnt);
  int n,m; cin >> n >> m;
  for(int i = 1 ; i <= n ; ++i)
    {
      cin >> f[i];
      if(cnt[f[i]] > 0)
	re[f[i]] = 1;
      cnt[f[i]] = i;
    }
  for(int i = 1 ; i <= m ; ++i)
    cin >> b[i];
  for(int i = 1 ; i <= m ; ++i)
    {
      if(cnt[b[i]] == -1)
	{
	  cout << "Impossible\n";
	  return 0;
	}
    }
  for(int i = 1 ; i <= m ; ++i)
    {
      if(re[b[i]] == 1)
	{
	  cout << "Ambiguity\n";
	  return 0;
	}
    }
  cout << "Possible\n";
  for(int i = 1 ; i <= m ; ++i)
    {
      cout << cnt[b[i]] << " ";
    }
  cout << "\n";
  return 0;
}
