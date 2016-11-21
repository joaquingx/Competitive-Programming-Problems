#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
map < pair<ll,ll> , ll > m;
set<ll> s;


ll lca(ll u , ll v)
{
  ll lc = 1;
  s.clear();
  while(u != 1)
    {
      s.insert(u);
      u/=2;
    }
  s.insert(1);
  while(v != 1)
    {
      if(s.find(v) != s.end())
	{
	  lc = v;
	  break;
	}
      v/=2;
    }
  return lc;
}

void ssp(ll u , ll v, ll w)
{
  ll p;
  bool termine=0;
  if(v > u)
    swap(u,v);
  // cout << "aaa\n";
  ll lc = lca(u,v);
  // cout << lc << "\n";
  while(u != lc)
    {
      if(u == v)
	{
	  termine=1;
	  break;
	}
      p = u/2;
      m[{u,p}] += w;
      m[{p,u}] += w;
      u = p;
    }
  if(!termine)
    {
      while(v != lc)
	{
	  p = v/2;
	  m[{v,p}] += w;
	  m[{p,v}] += w;
	  v = p;	  
	}
    }
}

ll dame(ll u , ll v)
{
  bool termine=0;
  ll ans =0,p;
  if(v > u)
    swap(u,v);
  ll lc = lca(u,v);
  while(u != lc)
    {
      if(u == v)
	{
	  termine=1;
	  break;
	}
      p = u/2;
      ans += m[{p,u}];
      u = p;
    }
  if(!termine)
    {
      while(v != lc)
	{
	  p = v/2;
	  ans += m[{p,v}];
	  v = p;	  
	}
    }
  return ans;
}



int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  ll k,u,v,w;
  int n; cin >> n;
  for(int i = 0 ;i < n ; ++i)
    {
      cin >> k;
      if(k == 1)
	{
	  cin >> u >> v >> w;
	  ssp(u,v,w);
	}
      else
	{
	  cin >> u >> v;
	  cout << dame(u,v) << "\n";
	}      
    }
  return 0;
}
