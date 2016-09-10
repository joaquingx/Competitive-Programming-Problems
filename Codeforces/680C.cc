#include <bits/stdc++.h>
#define MAXN 121
#define TEST 15
using namespace std;
int primes[TEST] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int num[MAXN];


int main()
{
  bool prime=1;
  memset(num, 0 , sizeof num);
  int n = MAXN;
  for(int i = 0 ; i < TEST ; ++i)
    {
      printf("%d\n", primes[i]);
      fflush(stdout);
      char response[3];
      scanf("%s", response);
      if (strcmp(response, "yes") == 0)
	num[primes[i]] = 1;
    }
  int cc=0;
  for(int i = 0 ; i < MAXN ; ++i)
    {
      if(num[i] >= 1)	
	{
	  ++cc;
	}
    }
  if(cc>=2)
    {
      printf("composite\n");
      fflush(stdout);
      return 0;
    }
  for(int i = 0 ; i < MAXN ; ++i)
    {
      if(num[i] == 1)
	{
	  int cnt = i*i;
	  while(cnt < MAXN)
	    {
	      printf("%d\n",cnt);
	      fflush(stdout);
	      char response[3];
	      scanf("%s", response);
	      if (strcmp(response, "yes") == 0)
		{
		  printf("composite\n");
		  fflush(stdout);
		  return 0;
		}
	      cnt *= i;
	    }
	}
    }
  printf("prime\n");
  fflush(stdout);
  return 0;
}
