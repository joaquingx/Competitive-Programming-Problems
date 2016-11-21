#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n ,m,matrix[MAXN][MAXN] ; cin >> n >> m;
  for(int i = 0 ;i < n ; ++i)
    for(int j = 0 ; j < m ; ++j)
      {
	cin >> matrix[i][j];
      }
  long long ans=0;
  for(int i  = 0 ;i < n ; ++i)
    {
      long long car = 0;
      bool left=0;
      for(int j = 0 ; j < m ; ++j)
	{
	  if(matrix[i][j] == 0)
	    ++car;
	  else
	    {
	      if(left)
		{
		  ans += car*2;
		}
	      if(!left)
		{
		  left=1;
		  ans+= car;
		}
	      car = 0;
	    }
	}
      if(matrix[i][m-1] != 1 and left)
	ans += car;
      // cout << ans << "\n";
    }
  for(int i  = 0 ;i < m ; ++i)
    {
      long long car = 0;
      bool left=0;
      for(int j = 0 ; j < n ; ++j)
	{
	  if(matrix[j][i] == 0)
	    ++car;
	  else
	    {
	      if(left)
		{
		  ans += car*2;
		}
	      if(!left)
		{
		  left=1;
		  ans+= car;
		}
	      car = 0;
	    }
	}
      if(matrix[n-1][i] != 1 and left)
	ans += car;
      // cout << ans << "\n";
    }
  cout << ans << "\n";  
  return 0;
}
