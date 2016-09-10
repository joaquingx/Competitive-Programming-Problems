#include <bits/stdc++.h>
#define MAXN int(1e5+10)
using namespace std;
typedef long long ll;
int main()
{
  ll ans = 0 ;
  map<int,int> v;
  int n; cin >> n;
  for(int i = 0 ;i < n ; ++i)
    {
      int k,q=1; cin >> k;
      for(int j = 1 ; j <= 32 ; ++j)
	{
	  ans += v[q - k];
	  q *= 2;
	}
      if(v.count(k) <  0)
	v[k] = 1;
      else
	++v[k];
    }
  cout << ans << "\n";
  return 0;
}
