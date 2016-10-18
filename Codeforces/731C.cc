#include <bits/stdc++.h>
#define MAXN int(1e5 * 2+10)
using namespace std;
vector< vector<int > > Adj;
int maxval,cnt,vis[MAXN],a[MAXN],vec[MAXN];
set<int> gg;

void init()
{
  memset(vis,0,sizeof vis);
}
void dfs(int u)
{
  vis[u]=1;
  ++vec[a[u]];
  ++cnt;
  gg.insert(a[u]);
  if( maxval < vec[a[u]])
    {
      maxval = vec[a[u]];
    }
  for(int v : Adj[u])
    {
      if(!vis[v])
	dfs(v);
    }
}


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  init();
  int n,m,k,ans=0; cin >> n >> m >> k;
  Adj.resize(n);
  for(int i= 0 ;i < n ; ++i)
    cin >> a[i];
  for(int  j = 0 ; j < m ; ++j)
    {
      int l,r; cin >> l >> r;
      --l,--r;
      Adj[l].push_back(r);
      Adj[r].push_back(l);
    }
  for(int i= 0 ;i < n; ++i)
    if(!vis[i])
      {
	for(auto it = gg.begin() ; it != gg.end() ; ++it)
	  {
	    vec[*it] = 0;
	  }
	gg.clear();
	maxval = -1;
	cnt = 0;
	dfs(i);
	ans += cnt - maxval;
      }
  cout << ans << "\n";
  return 0;
}
