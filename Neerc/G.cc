#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector< pair < ll , ll > > v,a,ans;

bool isinterval(ll a , ll b , ll key)
{
  if(key >= a and key <= b)
    return 1;
  return 0;
}

int main()
{
  int n; cin >> n;
  v.resize(n);
  for(int i = 0 ;i < n; ++i)
    {
      cin >> v[i].first >> v[i].second ;
      v[i].second = v[i].first + v[i].second -1;
    }
  a.push_back({0,0});
  for(int i = 0 ; i < n; ++i)
    {
      sort(a.begin(), a.end());
      // for(int j = 0 ; j < a.size() ; ++j)
      // 	cout << a[j].first << " " << a[j].second << "\n";
      // cout << "\n";
      bool ff=0;
      for(int j = 0 ; j < a.size() ; ++j)
	if(isinterval(a[j].first,a[j].second, v[i].first) or
	   isinterval(a[j].first, a[j].second, v[i].second) or
	   isinterval(v[i].first,v[i].second,a[j].first) or
	   isinterval(v[i].first,v[i].second,a[j].second)
	   )
	  {
	    ff = 1;
	    break;
	  }
      if(ff)
	{
	  int idx = a.size() - 1;
	  ll cc = v[i].second - v[i].first + 1;
	  pair<ll,ll> com = a[0];
	  for(int j = 1 ; j < a.size() ; ++j)
	    {
	      if(a[j].first - com.second - 1 >= cc)
		{
		  idx = j-1;
		  break;
		}
	      com = a[j];
	    }
	  a.push_back( {a[idx].second + 1 , a[idx].second + cc } ) ;
	  ans.push_back( {a[idx].second + 1 , a[idx].second + cc } ) ;
	}
      else
	{
	  a.push_back( { v[i].first,v[i].second } );
	  ans.push_back( { v[i].first,v[i].second } );
	}
    }
  sort(a.begin() , a.end() );
  for(int i = 0 ;i < ans.size() ; ++i)
    cout << ans[i].first  << " " << ans[i].second << "\n";
  return 0;
}
