#include <bits/stdc++.h>
#define MAXN 110
using namespace std;
typedef long long ll;
vector< vector<int> > List;
ll cnt[MAXN],mark[MAXN];
ll n,m,s,t ;

void bfs(ll source,ll  infection)
{
  for(ll i = 0 ; i < List[source].size() ; ++i)
    {
      cnt[List[source][i]]+= infection;
      mark[List[source][i]] = 1;
      // cout << "visitas : "<<List[source][i] <<  " " << cnt[List[source][i]]<< "\n";
    }
}

void solve()
{
  ll ans;
  vector<ll> p; p.push_back(s); vector<ll> inf ; inf.push_back(1);
  for(ll j = 0 ; j < t ; ++j)
    {
      ans=0;
      memset(mark , 0 , sizeof mark);
      memset(cnt, 0 , sizeof cnt);
      for(int i = 0 ; i < p.size() ; ++i)
	{
	  bfs(p[i],inf[i]);
	}
      p.erase(p.begin(),p.end());
      inf.erase(inf.begin(), inf.end());
      for(int i = 0 ; i < MAXN ; ++i)
	{
	  if(mark[i] == 1)
	    {
	      p.push_back(i);
	      inf.push_back(cnt[i]);
	      ans += cnt[i];
	    }
	}
    }
  cout << ans << "\n";
}



int main()
{
  memset(cnt , 0 , sizeof cnt);
  cin >> n >> m >> s >> t;
  List.resize(n);
  for(int i  = 0 ; i < m ; ++i)
    {
      ll a, b; cin >> a >> b;
      List[a].push_back(b);
      List[b].push_back(a);
    }
  if(t  == 0)
    {
      cout << 1 << "\n";
      return 0;
    }
  solve();
  return 0;
}
