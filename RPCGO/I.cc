#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
  ll n ; cin >> n;
  ll ans = 1;
  for(ll i = 1 ; i <= n*3 ; ++i)
    {
      ans *= 2;
    }
  cout << ans << "\n";
  return 0;
}
