#include <bits/stdc++.h>
#define NMAX 201
#define MMAX 201
using namespace std;
typedef long long ll;
// based on partition algorithm 
// http://stackoverflow.com/questions/14053885/integer-partition-algorithm-and-recursion


ll dp[NMAX][MMAX];
int q,k;

void init()
{
  for(int i = 0 ; i < NMAX ; ++i)
    for(int j = 0 ; j < MMAX ; ++j)
      dp[i][j] = -1;
}

//top down
ll solve(int n, int m)
{
  if(n < 0 or  m == 0 or m < k) return 0;
  if(n == 0) return 1;
  if(n < k) return 0;
  if(dp[n][m] == -1)
    dp[n][m] = solve(n-m,m) + solve(n,m-1);
  return dp[n][m];
}


int main()
{
  int t; scanf("%d",&t);
  while(t--)
    {
      init();
      scanf("%d %d",&q,&k);
      if(k > q)
	printf("0\n");
      else
	{
	  solve(q,q);
	  printf("%ld\n",dp[q][q]);
	}
    }
  return 0;
}
