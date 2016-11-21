#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll ans=0;
  int n,m; cin >> n >> m;
  for(int i = 1 ; i <= n ; ++i)
    {
      ans += ll((m + (i)%5) / 5);
    }
  cout << ans << "\n";
  return 0;
}
