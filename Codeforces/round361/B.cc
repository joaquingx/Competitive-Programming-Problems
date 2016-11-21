#include <bits/stdc++.h>
#define MAXN int(2*1e5+100)
using namespace std;
int ans[MAXN],v[MAXN],vis[MAXN],n;
vector< vector<int > >Adj;

// int solve1(int u)
// {
//   if(vis[u])
//     return ans[u];
//   if(u > 0)
//     ans[u] = min(ans[u], solve1(u-1) + 1);
//   // if(u < n-1)
//   //   ans[u] = min(ans[u], solve1(u+1) + 1);
//   for(int v : Adj[u])
//     if(v < u)
//       ans[u] = min(ans[u], solve1(v) + 1);
//   vis[u] = 1;

// }

// int solve2(int u)
// {
//   if(vis[u])
//     return ans[u];
//   if(u < n-1)
//     ans[u] = min(ans[u], solve2(u+1) + 1);
//   for(int v : Adj[u])
//     if(v > u)
//       ans[u] = min(ans[u], solve2(v) + 1);
//   vis[u] = 1;
// }

int main()
{
  cin >> n;
  Adj.resize(n);
  for(int i = 0 ; i < n ; ++i)
    {
      cin >> v[i];
      --v[i];
      if(v[i] != i)
	Adj[i].push_back(v[i]);
      if(i > 0)
	Adj[i].push_back(i-1);
      if(i < n-1 )
	Adj[i].push_back(i+1);
    }
  for(int i= 0;i < n ; ++i)
    ans[i] = i;
  memset(vis,0,sizeof vis);
  queue<int> Q; Q.push(0);
  vis[0]= 1;
  while(!Q.empty())
    {
      int u = Q.front(); Q.pop();
      // cout << u << "\n";
      for(int v : Adj[u])
	{
	  if(!vis[v])
	    {
	      ans[v] = min(ans[v],ans[u] + 1);
	      Q.push(v);
	      vis[v] = 1;
	    }
	}
    }  
  for(int i= 0 ;i < n ; ++i)
    cout << ans[i] << " ";
  cout << "\n";
  return 0;	     
}
