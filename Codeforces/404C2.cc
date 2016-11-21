#include <bits/stdc++.h>
using namespace std;
vector< pair< int, int > > a,Adj;
vector<int> cnt;


int main()
{
  bool sis=1;
  int n,m; cin >> n >> m;
  a.resize(n);
  cnt.assign(n,0);
  for(int i= 0 ; i < n ; ++i)
    {
      cin >>a[i].first;
      a[i].second = i;
    }
  sort(a.begin() , a.end() );
  if(a[0].first != 0)
    {
      cout << "-1" << "\n";
      return 0;
    }
  queue< pair<int , int > > Q;
  pair<int,int> cur;
  Q.push(a[0]);
  for(int i = 1 ; i < n ; ++i)
    {
      cur = Q.front();
      while(a[i].first - 1 != cur.first or cnt[cur.second] >= m or cnt[a[i].second]>= m)
	{
	  if(Q.empty())
	    {
	      cout << -1 << "\n";
	      return 0;
	    }
	  Q.pop();
	  cur = Q.front();
	}
      Adj.push_back({cur.second,a[i].second});
      ++cnt[cur.second];
      ++cnt[a[i].second];
      Q.push(a[i]);
    }
  cout << Adj.size() << "\n"; 
  for(int i = 0 ;i < Adj.size() ; ++i)
    cout << Adj[i].first + 1 << " " << Adj[i].second+1 << "\n";
  return 0;
}
