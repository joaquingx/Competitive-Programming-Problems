#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n,mini,partial,ans=0 ; cin >> n;
  ll a,b,c; cin >> a >> b >> c;
  if(a < (b-c))
    {
      cout << n/a << "\n";
    }
  else{
    ll ans = b * (n-c) / (b-c);
    
    cout << ans <
  }
  return 0;
}
