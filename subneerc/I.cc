#include <bits/stdc++.h>
#define MAXN int(6*1e6)
using namespace std;
bool mark[MAXN];

int main()
{
  int n ; cin >> n;
  memset(mark,0,sizeof mark);
  for(int i = 0 ;i < n ; ++i)
    {
      int l,r; cin >> l >> r;
      for(int j = l ; j <= r ; ++j)
	mark[j] = 1;
    }
  for(int i = 1 ;i < MAXN ; ++i)
    {
      int cnt =	0;
      if(mark[i])
	for(int j = i ; j < i + 180 ; ++j)
	  if(mark[j])
	    ++cnt;
      // cout << cnt << "\n";
      if(cnt > 90)
	{
	  cout << "No\n";
	  return 0;
	}
    }
  cout << "Yes\n";
  return 0;
}
