#include <bits/stdc++.h>
#define MAXN 101
using namespace std;
int dp[MAXN][MAXN];
int mex[5*MAXN];


inline int inside(int idx , int jdx)
{
  int xori;
  bool is = 0;
  for(int i = 1 ; i <= idx ; ++i)
    {
      for(int j = 1 ; j <= jdx ; ++j)
	{
	  xori = dp[i-1][j-1] ^ dp[i-1][jdx-j] ^ dp[idx - i][j-1] ^ dp[idx -i][jdx-j];
	  mex[xori]=1;
	}      
    }
  for(int i = 0 ; i < 5*MAXN ; ++i)
    {
      if(mex[i] == 0)
	return i;
    }
  return 0;
}


void solve()
{
  memset(dp , -1 ,sizeof dp);
  for(int i = 0 ; i < MAXN ; ++i)
    dp[0][i] = dp[i][0]  = 0;
  for(int i = 1 ; i < MAXN ; ++i)
    {
      dp[i][1] =  dp[1][i] = 1;
    }
  for(int i = 2 ; i < MAXN ; ++i)
    {
      for(int j = i; j < MAXN ; ++j)
  	{
  	  memset(mex , 0 , sizeof mex);
  	  if(dp[i][j] == -1)
  	    dp[i][j] = dp[j][i] = inside(i,j);
  	}
    }
  // for(int i = 0 ; i < 10 ; ++i)
  //   {
  //     for(int j = 0 ; j < 10 ; ++j)
  // 	cout << dp[i][j] << " ";
  //     cout << "\n";
  //   }
}



int main()
{
  ios_base::sync_with_stdio(0);
  solve();
  int T,a,b;
  scanf("%d",&T);
  while(T--)
    {
      scanf("%d %d",&a , &b);
      if(dp[a][b] > 0)
	printf("1\n");
      else
	printf("2\n");
    }
  return 0;
}
