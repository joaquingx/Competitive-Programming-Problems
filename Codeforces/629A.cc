#include <bits/stdc++.h>
#define MAXN 110
using namespace std;

int main()
{
  int n; cin >> n;
  char Matrix[MAXN][MAXN];
  for(int i = 0 ; i < n ; ++i)
    for(int j = 0 ; j < n; ++j)
      cin >> Matrix[i][j];
  int ans = 0 ;
  for(int i = 0 ; i < n ; ++i)
    {
      int cnt = 0;
      for(int j = 0 ; j < n; ++j)
	if(Matrix[i][j]  == 'C')
	  ++cnt;
      if(cnt > 1)
	ans+= ((cnt-1)*cnt)/2;
    }
  for(int i = 0 ; i < n ; ++i)
    {
      int cnt = 0;
      for(int j = 0 ; j < n; ++j)
	if(Matrix[j][i]  == 'C')
	  ++cnt;
      if(cnt > 1)
	ans+= ((cnt-1)*cnt)/2;
    }
  cout << ans << "\n";
  return 0;
}
