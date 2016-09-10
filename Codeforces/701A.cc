#include <bits/stdc++.h>
#define MAXN 10010
using namespace std;


int main()
{
  int mark[MAXN];
  vector< pair<int,int> >  ans;
  int v[MAXN];
  int n; cin >> n;
  for(int  i  = 0 ; i < n ; ++i)
    {
      cin >> v[i];
    }
  for(int i = 2 ; i < MAXN ; ++i)
    {
      memset(mark, 0 , sizeof mark);
      ans.clear();
      ans.resize(0);
      for(int j = 0 ; j < n ;j++)
	{
	  for(int k = 0  ; k < n ; ++k)
	    if(v[j] + v[k] == i  and k != j and mark[k] == 0 and mark[j] == 0)
	      {
		mark[j] = 1;
		mark[k] = 1;
		ans.push_back({j,k});
	      }
	}
      if(ans.size()== n/2)
	break;
    }
  for(int i = 0 ;i < ans.size() ; ++i)
    {
      cout << ans[i].first + 1 << " " << ans[i].second + 1<<  "\n";
    }
  return 0;
}
