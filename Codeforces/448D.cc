#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll fn(ll n, ll m , ll x)
{
  ll ans = 0;
  for(ll i = 1 ; i  <= n ; ++i)
    {
      ans += min(m,x/i);
    }
  return ans;
}

ll bs(ll ini, ll fin,ll n , ll m,ll k)
{
  if(fin - ini > 0)
    {
      ll med = (ini + fin )/2;
      if(fn(n,m,med) < k)
	return bs(med + 1,fin,n,m,k);
      else
	return bs(ini,med,n,m,k);
    }
  return ini;
  
}


int main()
{
  ll n,m,k; cin >> n >> m >> k;
  cout << bs(1,n*m+1,n,m,k) << "\n";
  return 0;
}
