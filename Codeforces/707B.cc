#include <bits/stdc++.h>
#define INF int(2e9)
using namespace std;
vector < vector < pair < int , int > > > Adj;
vector<int> v;
map<int,int> vis;


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n,m,k; cin >> n >> m >> k;
  Adj.resize(n);
  v.resize(k);
  for(int i = 0;i < m ; ++i)
    {
      int l,r,w; cin >> l >> r >> w;
      --l;--r;
      Adj[l].push_back({r,w});
      Adj[r].push_back({l,w});
    }
  for(int i = 0 ; i < k ; ++i)
    {
      cin >> v[i];
      --v[i];
      vis[v[i]] = 1;
    }
  int ans = INF;
  for(int i = 0 ; i < k ; ++i)
    {
      for(int j = 0 ; j < Adj[v[i]].size() ; ++j)
	{
	  int val = Adj[v[i]][j].first;
	  if(vis.find(val) == vis.end())
	    ans = min(ans, Adj[v[i]][j].second);
	}
    }
  if(ans < INF)
    cout << ans << "\n";
  else
    cout << -1 << "\n";
}
