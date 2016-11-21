#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll ans,l1,r1,l2,r2,k; cin >> l1 >> r1 >> l2 >> r2 >> k;
  pair<ll,ll > inter = {max( l1 ,l2 ) , min(r1,r2)};
  if(inter.first > inter.second)
    {
      cout << 0 << "\n";
      return 0;
    }
  ans = inter.second - inter.first + 1;
  if(inter.first <= k and inter.second >= k)
    ans--;
  cout << ans << "\n";
  return 0;
}
