#include <bits/stdc++.h>
#define MAXN int(30)
using namespace std;

int vis[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};


int main()
{
  set< pair<int , int > > ifin;
  vector<int> ans,a;
  int n; cin >> n;
  a.resize(n);
  for(int i = 0 ;i < n; ++i)
    {
      cin >> a[i];
    }
  for(int i = 0; i < MAXN ; ++i)
    {
      int cnt = i,cntt=0;
      for(int j = 0 ; j < n ; ++j)
	{
	  if(a[j] != vis[cnt])
	  {
	    break;
	  }
	  cnt = (cnt + 1) % MAXN;
	  ++cntt;
	}
      if((cntt) == n and ifin.find({i,cnt}) == ifin.end() and ifin.find({cnt,i}) == ifin.end())
	{
	  ans.push_back(cnt);
	  ifin.insert({i,cnt});
	}
    }
  if(ans.size() > 1) {
    cout << -1 << "\n";
    return 0;
  }
  cout << (vis[ans[0]] > a[n-1] ? "UP" : "DOWN")  << "\n";
  return 0;
}
