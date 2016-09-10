#include <bits/stdc++.h>
#define BITS 6
using namespace std;
typedef long long ll;
#define MOD ll(1e9+7)
map<char,ll> mapeo;
void init()
{
  for(int i = 0 ; i < 10 ; ++i)
    mapeo[char(i+48)] = ll(i);
  for(int i = 10 ; i < 36 ; ++i)
    mapeo[char(i+55)] = ll(i);
  for(int i = 36 ; i < 62; ++i)
    mapeo[char(i+61)] = ll(i);
  mapeo['-'] = 62;
  mapeo['_'] = 63;
}

inline ll tobin(ll a)
{
  string ans;
  ll aux = a;
  while(aux > 0)
    {
      ll ac = aux  % 2;
      aux /= 2;
      ans += ( ac == 1 ? '1' : '0');
    }
  int tam = ans.size();
  for(int i  = 0 ; i < BITS-tam; ++i)
    ans += '0';
  // cout << ans << "\n";
  ll rpta=0;
  for(int i = 0 ; i < ans.size() ; ++i)
    if(ans[i]=='0')++rpta;
  return rpta;
}


int main()
{
  init();
  ll ans = 0;
  string pat; cin >> pat;
  for(int i = 0 ; i < pat.size() ; ++i)
    {
      // cout << mapeo['a'] << "\n";
      ans += tobin(mapeo[pat[i]]);
    }
  ll rpta=1;
  for(int i = 0 ; i < ans ; ++i)
    {
      rpta = (rpta * 3) %MOD;
    }
  cout << rpta << "\n";
  return 0;
}
