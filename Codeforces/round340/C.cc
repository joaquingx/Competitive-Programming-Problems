#include <bits/stdc++.h>
using namespace std;
#define MAXN 2010
typedef long long ll;
#define INF ll(1e18)
ll eucl(pair<ll,ll> p1 , pair<ll,ll> p2)
{
  return (p1.first-p2.first)* (p1.first-p2.first) + (p1.second - p2.second)*(p1.second - p2.second);
}

int main()
{
  int n,mark[MAXN]; cin >> n;
  pair<ll,ll> f1,f2;
  vector< pair<ll,ll > > l(n+2);
  cin >> f1.first >> f1.second >> f2.first >> f2.second;
  ll distf1=0,distf2=0,ans=INF;
  for(int i = 0 ;i < n ; ++i)
    cin >> l[i].first >> l[i].second;
  for(int i = 0;i < n ; ++i)
    {
      distf1 = max(eucl(l[i],f1),distf1);
      distf2 = max(eucl(l[i],f2),distf2);
    }
  ans = min(ans,min(distf1,distf2));
  for(int i = 0 ;i < n ; ++i)
    {
      distf1 = eucl(l[i],f1);
      memset(mark,0,sizeof mark);
      for(int j = 0  ;j <  n ; ++j)
	{
	  if(eucl(f1,l[j]) <= distf1)
	    mark[j] =1;
	}
      distf2 = 0;
      for(int j = 0 ;j < n ; ++j)
	if(!mark[j])
	  {
	    distf2 = max(distf2,eucl(l[j],f2));
	  }
      ans = min(ans , distf2 + distf1);
    }
  cout << ans  << "\n";
  return 0;
}
