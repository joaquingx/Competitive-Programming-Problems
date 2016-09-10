#include <bits/stdc++.h>
#define MAXN 51
using namespace std;
int t, matrix[MAXN][MAXN], dp[MAXN],mex[MAXN];
int pos;


inline int getmex(int idx)
{
  for(int i = pos ; i < MAXN; ++i )
    if(mex[i] == 0)
      {
	pos = i;
	break;
      }
  return pos;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int t,n,m,grundy,ini; scanf("%d",&t);
  while(t--)
    {
      int n,m ; scanf("%d %d",&n,&m);
      for(int i = 0 ; i < n ; ++i)
	for(int j = 0 ; j < m ; ++j)
 	  scanf("%d",&matrix[i][j]);
      grundy = 0;
      for(int i = 0  ; i < n ; ++i)
	{
	  ini = 0;
	  for(int j = m-1 ; j >= 0 ; --j)
	  {
	    pos=0;
	    memset(mex,0,sizeof mex);
	    dp[0] = ini;
	    mex[ini] = 1;
	    for(int k = 1;  k <= matrix[i][j] ; ++k)
	      {
		dp[k] = getmex(k);
		mex[dp[k]] = 1;
	      }
	    ini = dp[matrix[i][j]];
	  }
	  grundy ^= ini;
	}
      if(grundy > 0)
	printf("FIRST\n");
      else
	printf("SECOND\n");
    }
  return 0;
}
