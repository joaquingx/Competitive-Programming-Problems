#include <bits/stdc++.h>
#define MAXN 110
using namespace std;
typedef long long ll;

int main()
{
  bool flag=0;
  int n,idx=-1,cnt=0,unos=0; cin >> n;
  int v[MAXN];
  for(int i = 0 ;i < n; ++i)
    {
      cin >> v[i];
      if(v[i] == 1)
	{
	  if(!flag)
	    {
	      flag=1;
	      idx = i;//adasda
	    }
	  ++unos;
	}
    }
  if(idx == -1)
    {
      cout << 0 << "\n";
      return 0;
    }
  ll ans = 1;
  for(int i = idx+1 ; i < n;++i)
    {
      ++cnt;
      if(v[i] == 1)
	{
	  ans *= ll(cnt);
	  cnt=0;
	}
    }
  cout << ans << "\n";  
  return 0;
}
