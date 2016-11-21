#include <bits/stdc++.h>
#define MAXN 110
using namespace std;

int main()
{
  int c,m ; cin >>  c >> m;
  int a[MAXN][MAXN],ans[MAXN][MAXN];
  for(int i = 0 ;i < m ; ++i)
    {
      for(int j = 0 ; j < c ; ++j)
	{
	  cin >> a[i][j];
	}
    }
  memset(ans,0,sizeof ans);
  for(int i = 0 ; i < c ; ++i)
    {
      // for(int j = m-1 ; j >= 0 ; --j)
      for(int j = 0 ;j < m ; ++j)
	{
	  for(int k = 0 ; k < c ; ++k)
	    {
	      // if(j == 0)
	      // 	ans[j][i] = a[j][i];
	      // else
	      // 	ans[j][i] = max(ans[j-1][k] + a[j][i], ans[j][i]);
	    }
	}
    }
  for(int i = 0 ;i < m ; ++i)
  {
    for(int j = 0 ; j < c ; ++j)
  	{
  	  cout << ans[i][j] << " " ;
  	}
    cout << "\n";
  }
  int res = -1;
  for(int i = 0 ;i < c ; ++i)
    {
      for(int j = 0 ; j < m ; ++j)
	res = max(res,ans[j][i]);
    }
  cout << res << "\n";
  return 0;
}

