#include <bits/stdc++.h>
#define MAXN int(1e5+10)
using namespace std;
int v[MAXN];

int main()
{
  int n,h,k,ans=0; cin >> n >> h >> k;
  for(int i = 0 ; i < n ; ++i)
    {
      cin >> v[i];
    }
  int actual,ant=v[0];
  for(int i = 1 ; i < n ; ++i)
    {
      if(ant + v[0] <= h)
	{
	  ant += v[0];
	  continue;
	}
      else
	{
	  ans += ant/k;
	}
	
    }
  if(ant != 0)
    ans++;
  cout << ans << "\n";
  return 0;
}
