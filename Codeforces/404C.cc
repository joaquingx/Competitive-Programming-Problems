#include <bits/stdc++.h>
using namespace std;
vector< pair<int, int > > a,Adj;
vector<int> cnt;

int main()
{
  ios_base::sync_with_stdio(0);
  int n,k; cin >> n >> k;
  a.resize(n);
  cnt.assign(n,0);
  for(int i= 0 ; i < n ; ++i)
    {
      cin >> a[i].first;
      a[i].second = i;
    }
  sort(a.begin() ,  a.end());
  if(a[0].first != 0)
    {
      cout << -1 << "\n";
      return 0;
    }  
  if(!a[0].second and !a[1].second)
    {
      cout << -1 << "\n";
      return 0;
    }
  queue<int> Q,Q2; Q.push(a[0].first) ;Q2.push(a[0].second);
  for(int i = 1 ;i < n ; ++i)
    {
      int v = Q.front();
      int vv = Q2.front();
      while(a[i].first-1 !=  v and !Q.empty())
	{
	  Q.pop();
	  Q2.pop();
	  v = Q.front();
	}
      if(Q.empty())
	{
	  cout << -1 << "\n";
	  return 0;
	}
      v=Q.front();
      if(a[i].first <= v)
	{
	  cout << -1 << "\n";
	  return 0;
	}
      vv = Q2.front();
      while(cnt[vv] >= k and !Q.empty())
	{
	  Q.pop();
	  Q2.pop();
	  vv=Q2.front();
	}
      if(Q.empty())
	{
	  cout << -1 << "\n";
	  return 0;
	}
      v = Q.front();
      if(a[i].first <= v)
	{
	  cout << -1 << "\n";
	  return 0;
	}
      Adj.push_back({vv,a[i].second});
      ++cnt[vv];
      ++cnt[a[i].second];
      Q.push(a[i].first);
      Q2.push(a[i].second);
    }  
  cout << Adj.size() << "\n";
  for(int i = 0 ; i < Adj.size() ; ++i)
    {
      cout << Adj[i].first + 1 << " " << Adj[i].second + 1 << "\n";
    }
  return 0;
}
