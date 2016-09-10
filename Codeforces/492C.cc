#include <bits/stdc++.h>
#define MAXN int(1e5+10)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
vector<pll> v;
bool compare(pll p , pll q)
{
  if(p.second == q.second)
    return p.first <  q.first;
  return p.second < q.second;
}

int main()
{
  ios_base::sync_with_stdio(0);
  ll n , r , a, f, carry=0,ans=0; cin >> n >> r >> a;
  for(int i = 0 ; i < n ; ++i)
    {
      ll x,y; cin >> x >> y;
      v.push_back({x,y});
      carry += x;
    }
  sort(v.begin() , v.end() ,compare);
  f = (n * a) - carry;
  for( int i = 0 ;  (n * a) > carry ; ++i)
    {
      ans += v[i].second * min((r-v[i].first),(n*a)-carry);
      carry += min(r-v[i].first, (n*a)-carry);
    }
  cout << ans << "\n";
}
